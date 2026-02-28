#pragma once
#include <opusfile.h>
#include <3ds.h>

#include <string.h>

inline namespace G3AudioManager
{
    constexpr int SAMPLE_RATE{48000};
    constexpr int SAMPLES_PER_BUF{SAMPLE_RATE * 120 / 1000};
    constexpr int CHANNELS_PER_SAMPLE{2};
    constexpr int THREAD_AFFINITY{-1};
    constexpr int THREAD_STACK_SZ{32 * 1024};
    constexpr size_t WAVEBUF_SIZE{SAMPLES_PER_BUF * CHANNELS_PER_SAMPLE * sizeof(int16_t)};

    inline const char* AUDIO_PATH{"romfs:/audio/Electroman.opus"};
    inline ndspWaveBuf s_waveBufs[3]{};
    inline int16_t *s_audioBuffer{nullptr};
    inline LightEvent s_event{};
    inline bool s_quit{false};

    inline bool audioInit()
    {
        // Setup LightEvent for synchronisation of audioThread {{very suspuiosucus}}
        LightEvent_Init(&s_event, RESET_ONESHOT);

        // Setup NDSP
        ndspChnReset(0);
        ndspSetOutputMode(NDSP_OUTPUT_STEREO);
        ndspChnSetInterp(0, NDSP_INTERP_POLYPHASE);
        ndspChnSetRate(0, SAMPLE_RATE);
        ndspChnSetFormat(0, NDSP_FORMAT_STEREO_PCM16);

        // Allocate audio buffer
        const size_t bufferSize{WAVEBUF_SIZE * (sizeof(s_waveBufs) / sizeof((s_waveBufs)[0]))};
        s_audioBuffer = (int16_t *)linearAlloc(bufferSize);
        if (!s_audioBuffer)
            return false;

        // Setup waveBufs for NDSP
        memset(&s_waveBufs, 0, sizeof(s_waveBufs));
        int16_t *buffer{s_audioBuffer};

        for (size_t i = 0; i < (sizeof(s_waveBufs) / sizeof((s_waveBufs)[0])); ++i)
        {
            s_waveBufs[i].data_vaddr = buffer;
            s_waveBufs[i].status = NDSP_WBUF_DONE;

            buffer += WAVEBUF_SIZE / sizeof(buffer[0]);
        }

        return true;
    }

    inline void audioExit()
    {
        ndspChnReset(0);
        linearFree(s_audioBuffer);
    }

    inline bool fillBuffer(OggOpusFile *opusFile_, ndspWaveBuf *waveBuf_)
    {
        // Decode samples until our waveBuf is full
        int totalSamples{0};
        while (totalSamples < SAMPLES_PER_BUF)
        {
            int16_t *buffer{waveBuf_->data_pcm16 + (totalSamples * CHANNELS_PER_SAMPLE)};
            const size_t bufferSize{static_cast<size_t>((SAMPLES_PER_BUF - totalSamples) * CHANNELS_PER_SAMPLE)};

            const int samples{op_read_stereo(opusFile_, buffer, bufferSize)};
            if (samples <= 0)
            {
                if (samples == 0)
                    break;
                break;
            }
            totalSamples += samples;
        }

        if (totalSamples == 0)
        {
            return false;
        }

        waveBuf_->nsamples = totalSamples;
        ndspChnWaveBufAdd(0, waveBuf_);
        DSP_FlushDataCache(waveBuf_->data_pcm16,
                           totalSamples * CHANNELS_PER_SAMPLE * sizeof(int16_t));

        return true;
    }

    inline void audioCallback(void *const nul_)
    {
        (void)nul_;

        if (s_quit)
            return;

        LightEvent_Signal(&s_event);
    }

    inline void audioThread(void *const opusFile_)
    {
        OggOpusFile *const opusFile{(OggOpusFile *)opusFile_};

        while (!s_quit)
        {
            for (size_t i = 0; i < (sizeof(s_waveBufs) / sizeof((s_waveBufs)[0])); ++i)
            {
                if (s_waveBufs[i].status != NDSP_WBUF_DONE)
                    continue;

                if (!fillBuffer(opusFile, &s_waveBufs[i]))
                    return;
            }

            LightEvent_Wait(&s_event);
        }
    }

    inline void playAudio()
    {
        // Open the Opus audio file
        int error{0};
        OggOpusFile *opusFile{op_open_file(AUDIO_PATH, &error)};
        if (error)
            return;

        // Audio in'it
        if (!audioInit())
            return;
        ndspSetCallback(audioCallback, nullptr);

        int32_t priority{0x30};
        svcGetThreadPriority(&priority, CUR_THREAD_HANDLE);
        priority += 1;
        priority = priority < 0x18 ? 0x18 : priority;
        priority = priority > 0x3F ? 0x3F : priority;

        [[maybe_unused]] const Thread threadId = threadCreate(audioThread, opusFile, THREAD_STACK_SZ, priority, THREAD_AFFINITY, false);
    }

    // inline void audioCleanup()
    // {
    //     // Signal audio thread to quit
    //     s_quit = true;
    //     LightEvent_Signal(&s_event);

    //     // Free the audio thread
    //     threadJoin(threadId, UINT64_MAX);
    //     threadFree(threadId);
    //     // Cleanup audio things and de-init platform features
    //     audioExit();
    //     ndspExit();
    //     op_free(opusFile);
    // }
}