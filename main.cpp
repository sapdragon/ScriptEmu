#include <iostream>
#include "Emulator/Engine/EmulatorEngine.hpp"
int main()
{

    g_EmulatorEngine.InitializeEngine();

    printf("ScriptEmu alpha\n Enter path to script:");

    std::string sPath;

    sPath.reserve( _MAX_PATH);

    std::cin >> sPath;
    
    g_EmulatorEngine.EmulateScript(sPath);

	auto aTraceData = g_EmulatorEngine.GetTraceData();

    /* print trace data */
    for (auto& aEventMessages : aTraceData )
    {
        for (auto& sMessage : aEventMessages.second)
            printf("Trace info | Event: %s | %s \n", aEventMessages.first.c_str(), sMessage.c_str());
    }

    system("pause");
}