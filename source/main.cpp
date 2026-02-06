// #include <string.h>
// #include <stdio.h>
// #include <stdlib.h>
#include <3ds.h>
#include <citro2d.h>

int main()
{
    gfxInitDefault();
    C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
    C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
    C2D_Prepare();
    cfguInit();

    C3D_RenderTarget *top{C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT)};
    C3D_RenderTarget *bottom{C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT)};

    // tryna load fonts rn
    C2D_TextBuf staticBuffer{C2D_TextBufNew(4096)};
    C2D_Text topText{};
    C2D_Text bottomText{};

    C2D_TextParse(&topText, staticBuffer, "Geometry Dash 3DS");
    C2D_TextParse(&bottomText, staticBuffer, "its for real.");
    C2D_TextOptimize(&topText);
    C2D_TextOptimize(&bottomText);

    // main loop
    while (aptMainLoop())
    {
        hidScanInput();
        u32 kDown = hidKeysDown();

        if (kDown & KEY_START)
            break; // exit game

        C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
        /* Render top */
        C2D_TargetClear(top, C2D_Color32(0x00, 0x66, 0xFF, 0xFF));
        C2D_SceneBegin(top);
        C2D_DrawText(&topText, C2D_WithColor | C2D_AlignCenter | C2D_AtBaseline, 200.0f, 120.0f, 0, 1.0f, 1.0f, C2D_Color32f(1, 1, 1, 1));

        /* Render bottom */
        C2D_TargetClear(bottom, C2D_Color32(0x00, 0x66, 0xFF, 0xFF));
        C2D_SceneBegin(bottom);
        C2D_DrawText(&bottomText, C2D_WithColor | C2D_AlignCenter | C2D_AtBaseline, 160.0f, 120.0f, 0, 1.0f, 1.0f, C2D_Color32f(1, 1, 1, 1));

        C3D_FrameEnd(0);
    }

    cfguExit();

    C2D_TextBufDelete(staticBuffer);

    // Deinit libs
    C2D_Fini();
    C3D_Fini();
    gfxExit();

    return 0;
}
