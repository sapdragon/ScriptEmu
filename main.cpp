#include <iostream>
#include <thread>
#include "Emulator/Engine/EmulatorEngine.hpp"
#include "Emulator/Gui/Gui.hpp"

int main()
{
	g_EmulatorEngine.InitializeEngine();
    g_EmuGui->Render();
}