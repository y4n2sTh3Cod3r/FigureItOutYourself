#include "cheats/aimbot.h"
#include "cheats/esp.h"
#include <thread>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    HWND hwnd = window::InitWindow(hInstance);
    if (!hwnd) return -1;

    if (!renderer::init(hwnd))
    {
        renderer::destroy();
        return -1;
    }


    aimbot::procID = memory::GetProcID(L"cs2.exe");
    aimbot::module_base = memory::GetModuleBaseAddress(aimbot::procID, L"client.dll");
    esp::pID = memory::GetProcID(L"cs2.exe");
    esp::modBase = memory::GetModuleBaseAddress(esp::pID, L"client.dll");

    std::thread read(esp::loop);

    while (!GetAsyncKeyState(VK_END))
    {
        esp::frame();

        if (GetAsyncKeyState(VK_LSHIFT))
            aimbot::frame();
    }

    renderer::destroy();
    UnregisterClass(L"overlay", hInstance);
}
