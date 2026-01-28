#include "lib.hpp"

void DrawFirstBox(GLFWwindow* window, const char* title, float cursorPosY, float cursorPosX) {
    // Set background color for the child window (RGBA: dark blue with 90% opacity)
    ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.086f, 0.082f, 0.161f, 0.9f));
    ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0.086f, 0.082f, 0.161f, 0.9f));
    ImGui::BeginChild("FirstBox", ImVec2(709, 327), true);
    ImGuiStyle& style = ImGui::GetStyle();
    style.ChildRounding = 15.0f;

     // Title text
    ImGui::SetCursorPos(ImVec2(cursorPosX + 10, cursorPosY - 50)); // Adjust Y position for title
    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
    ImGui::PushFont(g_fontStyles.Inter_24pt_Regular);
    ImGui::SetWindowFontScale(1.0f);
    ImGui::Text("%s", title);
    ImGui::PopFont();
    ImGui::PopStyleColor();

    ImGui::SetCursorPosX(20);
    DrawRAMGraph();
    //style.ChildBorderSize = 1.0f;
    //style.FrameRounding = 10.0f;
    // ImGui::Text("This is the first box content.");
    // Add more UI elements as needed

    ImGui::EndChild();
    // Don't forget to pop the style color after ending the child window
    ImGui::PopStyleColor();
    ImGui::PopStyleColor();
}

void DrawSecondBox(GLFWwindow* window, const char* title, float cursorPosY, float cursorPosX) {
    // Set background color for the child window (RGBA: dark blue with 90% opacity)
    ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.086f, 0.082f, 0.161f, 0.9f));
    ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0.086f, 0.082f, 0.161f, 0.9f));
    ImGui::BeginChild("SecondBox", ImVec2(378, 250), true);
    ImGuiStyle& style = ImGui::GetStyle();
    style.ChildRounding = 15.0f;

         // Title text
     
    ImGui::SetCursorPos(ImVec2(cursorPosX + 10, cursorPosY - 400)); // Adjust Y position for title
    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
    ImGui::PushFont(g_fontStyles.Inter_24pt_Regular);
    ImGui::SetWindowFontScale(1.0f);
    ImGui::Text("%s", title);
    ImGui::PopFont();
    ImGui::PopStyleColor();
    
    SetMemoryInfo();
    //style.ChildBorderSize = 1.0f;
    //style.FrameRounding = 10.0f;
    // ImGui::Text("This is the first box content.");
    // Add more UI elements as needed

    ImGui::EndChild();
    // Don't forget to pop the style color after ending the child window
    ImGui::PopStyleColor();
    ImGui::PopStyleColor();
}

void DrawThirdBox(GLFWwindow* window, float cursorPosY, float cursorPosX) {
    // Set background color for the child window (RGBA: dark blue with 90% opacity)
    ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.086f, 0.082f, 0.161f, 0.9f));
    ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0.086f, 0.082f, 0.161f, 0.9f));
    ImGui::BeginChild("ThirdBox", ImVec2(320, 250), true);
    ImGuiStyle& style = ImGui::GetStyle();
    style.ChildRounding = 15.0f;
    //style.ChildBorderSize = 1.0f;
    //style.FrameRounding = 10.0f;
    // ImGui::Text("This is the first box content.");
    // Add more UI elements as needed

    ImGui::EndChild();
    // Don't forget to pop the style color after ending the child window
    ImGui::PopStyleColor();
    ImGui::PopStyleColor();
}

void DrawFourthBox(GLFWwindow* window, const char* title, float cursorPosY, float cursorPosX) {
    // Set background color for the child window (RGBA: dark blue with 90% opacity)
    ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.086f, 0.082f, 0.161f, 0.9f));
    ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0.086f, 0.082f, 0.161f, 0.9f));
    ImGui::BeginChild("FourthBox", ImVec2(709, 327), true);
    ImGuiStyle& style = ImGui::GetStyle();
    style.ChildRounding = 15.0f;

    ImGui::SetCursorPos(ImVec2(cursorPosX + 10, cursorPosY - 670)); // Adjust Y position for title
    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
    ImGui::PushFont(g_fontStyles.Inter_24pt_Regular);
    ImGui::SetWindowFontScale(1.0f);
    ImGui::Text("%s", title);
    ImGui::PopFont();
    ImGui::PopStyleColor();
    //style.ChildBorderSize = 1.0f;
    //style.FrameRounding = 10.0f;
    // ImGui::Text("This is the first box content.");
    // Add more UI elements as needed

    ImGui::EndChild();
    // Don't forget to pop the style color after ending the child window
    ImGui::PopStyleColor();
    ImGui::PopStyleColor();
}