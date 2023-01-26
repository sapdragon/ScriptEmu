#include <iostream>
#include "Emulator/Engine/EmulatorEngine.hpp"
int main()
{

    g_EmulatorEngine.InitializeEngine();

    printf("ScriptEmu alpha\n");

    g_EmulatorEngine.EmulateScript(R"(local function on_paint()
    renderer.rect_filled_fade(vec2_t.new(5, 5), vec2_t.new(20, 20), color_t.new(255, 0, 0, 255), color_t.new(255, 0, 0, 255), color_t.new(0, 0, 0, 255), color_t.new(0, 0, 0, 255))
end

client.register_callback("paint", on_paint))");

	auto aTraceData = g_EmulatorEngine.GetTraceData();

    /* print trace data */
    for (auto& aEventMessages : aTraceData )
    {
        for (auto& sMessage : aEventMessages.second)
            printf("Trace info | Event: %s | %s \n", aEventMessages.first.c_str(), sMessage.c_str());
    }

    __debugbreak();
}