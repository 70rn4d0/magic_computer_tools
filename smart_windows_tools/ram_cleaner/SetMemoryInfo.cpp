#include "lib.hpp"

//powershell "Get-CimInstance Win32_PhysicalMemory | Select-Object Manufacturer, PartNumber, Speed, ConfiguredVoltage, FormFactor, SMBIOSMemoryType"



void SetRaminfo()
{
    RamInfo io;


    // Dummy data for testing
    io.type = "DDR4";
    io.speedMHz = 3200;
    io.latencyNs = 16;
    io.channels = 2;
    io.voltageV = 1.35f;
    io.formFactor = "DIMM";
    io.manufacturer = "Corsair";
    io.partNumber = "CMK16GX4M2B3200C16";
}


void SetMemoryInfo()
{


    SetRaminfo();

    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
    ImGui::PushFont(g_fontStyles.Inter_18pt_Regular);
    ImGui::SetWindowFontScale(1.0f);
    ImGui::SetCursorPosY(50);
    ImGui::SetCursorPosX(30);
    ImGui::Text("Type: %s", "DDR4");
    ImGui::SetCursorPosX(30);
    ImGui::Text("Speed: %d MHz", 3200);
    ImGui::SetCursorPosX(30);
    ImGui::Text("Latency: %d ns", 16);
    ImGui::SetCursorPosX(30);
    ImGui::Text("Channels: %d", 2);
    ImGui::SetCursorPosX(30);
    ImGui::Text("Voltage: %.2f V", 1.35f);
    ImGui::SetCursorPosX(30);
    ImGui::Text("Form Factor: %s", "DIMM");
    ImGui::SetCursorPosX(30);
    ImGui::Text("Manufacturer: %s", "Corsair");
    ImGui::SetCursorPosX(30);
    ImGui::Text("PartNumber: %s", "CMK16GX4M2B3200C16");
    ImGui::PopFont();
    ImGui::PopStyleColor();

}