#include <3ds.h>
#include <citro2d.h>
// my stuff
#include <G3SceneManager.h>
int main()
{
    gfxInitDefault();
    C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
    C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
    C2D_Prepare();
    C3D_RenderTarget *top{C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT)};
    C3D_RenderTarget *bottom{C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT)};

    //init scene manager
    G3SceneManager::getInstance().setcurrentScene(G3Scene::create(C2D_Color32(0x00, 0x66, 0xFF, 0xFF)));

    // main loop
    while (aptMainLoop())
    {
        hidScanInput();
        u32 kDown = hidKeysDown();

        if (kDown & KEY_START)
            break;
        if (kDown & KEY_A)
            G3SceneManager::getInstance().setcurrentScene(G3Scene::create(C2D_Color32(0x00, 0x66, 0xFF, 0xFF)));
        if (kDown & KEY_B)
            G3SceneManager::getInstance().setcurrentScene(G3Scene::create(C2D_Color32(0xFF, 0x46, 0x00, 0xFF)));
        
        G3SceneManager::getInstance().updateScene();
        
        C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
        /* Render top */
        C2D_TargetClear(top, C2D_Color32(0x00, 0x00, 0x00, 0xFF));
        C2D_SceneBegin(top);
        G3SceneManager::getInstance().drawSceneAtTop();
        /* Render bottom */
        C2D_TargetClear(bottom, C2D_Color32(0x00, 0x00, 0x00, 0xFF));
        C2D_SceneBegin(bottom);
        G3SceneManager::getInstance().drawSceneAtBottom();

        C3D_FrameEnd(0);
    }

    C2D_Fini();
    C3D_Fini();
    gfxExit();

    return 0;
}
