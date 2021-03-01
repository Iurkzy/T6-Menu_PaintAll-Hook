#include "pch.h"
#include <detours.h>


#include "addresses.h"

// Pregame Headers
#include "pregame_huds.h"
#include "pregame_funcs.h"
#include "pregame_menu.h"

typedef void (*Menu_PaintAll_t)(UINT64);
Menu_PaintAll_t Menu_PaintAll_s;

void _Hook(UINT64 p1)
{
    Menu_PaintAll_s(p1);
    drawText("T6 Hook by Lurkzy", 0, 15, 0.5, Color_s(255, 255, 0, 50), "fonts/720/normalFont", 2);
    initMenu();
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{

    switch (ul_reason_for_call)
    {
        case DLL_PROCESS_ATTACH:

            Menu_PaintAll_s = (Menu_PaintAll_t)DetourFunction((PBYTE)0x006A8890, (PBYTE)_Hook); break;

        case DLL_PROCESS_DETACH:

            DetourRemove((PBYTE)Menu_PaintAll_s, (PBYTE)_Hook); break;
    }
    return TRUE;
}
