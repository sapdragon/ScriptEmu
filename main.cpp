#include <iostream>
#include "Emulator/Engine/EmulatorEngine.hpp"
int main()
{

    g_EmulatorEngine.InitializeEngine();

    printf("ScriptEmu alpha\n");

    g_EmulatorEngine.EmulateScript(R"(local local_info = engine.get_player_info(engine.get_local_player())
local shit = local_info.steam_id64

local_info.name = shit)");

	auto aTraceData = g_EmulatorEngine.GetTraceData();

    /* print trace data */
    for (auto& aEventMessages : aTraceData )
    {
        for (auto& sMessage : aEventMessages.second)
            printf("Trace info | Event: %s | %s \n", aEventMessages.first.c_str(), sMessage.c_str());
    }

    __debugbreak();
}