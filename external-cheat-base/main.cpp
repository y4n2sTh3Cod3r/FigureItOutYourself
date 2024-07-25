#include "cheats/FindOutYourself.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{

    FindOutYourself::procID = memory::GetProcID(L"cs2.exe");
    FindOutYourself::module_base = memory::GetModuleBaseAddress(FindOutYourself::procID, L"client.dll");

    while (true)
    {
        if (GetAsyncKeyState(VK_LSHIFT))
            FindOutYourself::frame();
    }

    return 0;
}
