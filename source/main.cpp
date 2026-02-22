#include <3ds.h>
#include <citro2d.h>
// (G)eometryDash(3)DS inclues
#include "G3GameManager.h"

int main()
{
    gfxInitDefault();
    romfsInit();
    C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
    C2D_Init(10000);
    C2D_Prepare();
    C3D_RenderTarget *top{C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT)};
    C3D_RenderTarget *bottom{C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT)};

    // init game manager
    G3GameManager::getInstance();

    // main loop
    while (aptMainLoop())
    {
        G3GameManager::getInstance()->updateScene();

        C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
        /* Render top */
        C2D_TargetClear(top, C2D_Color32f(0.16f, 0.17f, 0.8f, 255));
        C2D_SceneBegin(top);
        G3GameManager::getInstance()->drawSceneAtTop();

        /* Render bottom */
        C2D_TargetClear(bottom, C2D_Color32(0x00, 0x00, 0x00, 0xFF));
        C2D_SceneBegin(bottom);
        G3GameManager::getInstance()->drawSceneAtBottom();

        C3D_FrameEnd(0);
    }

    C2D_Fini();
    C3D_Fini();
    romfsExit();
    gfxExit();

    return 0;
}
