#include "lib.hpp"

// Simple memory info
struct MemoryInfo {
    float usagePercent;
    SIZE_T totalPhys;
    SIZE_T availPhys;
};

static MemoryInfo GetMemoryInfo() {
    MEMORYSTATUSEX statex;
    statex.dwLength = sizeof(statex);
    if (!GlobalMemoryStatusEx(&statex)) {
        return {0.0f, 0, 0};
    }
    DWORDLONG total = statex.ullTotalPhys;
    DWORDLONG avail = statex.ullAvailPhys;
    float usage = 0.0f;
    if (total > 0) {
        usage = static_cast<float>(100.0 * (static_cast<double>(total - avail) / static_cast<double>(total)));
    }
    
    return { usage, static_cast<SIZE_T>(total), static_cast<SIZE_T>(avail) };
}

// Global data for graph
static float ramHistory[100] = {0};
static int historyIdx = 0;
static std::chrono::steady_clock::time_point lastUpdateTime = std::chrono::steady_clock::now();
static const int updateIntervalMs = 500; // Update every 500ms instead of every frame

void UpdateRAMGraph() {
    auto currentTime = std::chrono::steady_clock::now();
    auto elapsedMs = std::chrono::duration_cast<std::chrono::milliseconds>(
        currentTime - lastUpdateTime).count();
    
    // Only update the graph data every updateIntervalMs milliseconds
    if (elapsedMs >= updateIntervalMs) {
        auto mem = GetMemoryInfo();
        ramHistory[historyIdx] = mem.usagePercent;
        historyIdx = (historyIdx + 1) % 100;
        lastUpdateTime = currentTime;
    }
}

void DrawRAMGraph() {
    ImPlotStyle& style = ImPlot::GetStyle();
    ImVec4 originalPlotBg = style.Colors[ImPlotCol_PlotBg];
    ImVec4 originalFrameBg = style.Colors[ImPlotCol_FrameBg];
    ImVec4 originalAxisGrid = style.Colors[ImPlotCol_AxisGrid];
    
    // Transparent backgrounds
    style.Colors[ImPlotCol_PlotBg] = ImVec4(0.047f, 0.055f, 0.122f, 0.0f);
    style.Colors[ImPlotCol_FrameBg] = ImVec4(0.047f, 0.055f, 0.122f, 0.0f);
    style.Colors[ImPlotCol_AxisGrid] = ImVec4(0.2f, 0.2f, 0.3f, 0.3f);
    
    // Draw plot
    if (ImPlot::BeginPlot("##memory", ImVec2(-1, 250), ImPlotFlags_NoTitle | ImPlotFlags_NoLegend)) {
        ImPlot::SetupAxes("", "", 
            ImPlotAxisFlags_NoLabel | ImPlotAxisFlags_NoTickLabels | ImPlotAxisFlags_NoTickMarks,
            ImPlotAxisFlags_NoLabel | ImPlotAxisFlags_NoTickLabels | ImPlotAxisFlags_NoTickMarks);
        ImPlot::SetupAxesLimits(0, 100, 0, 100, ImGuiCond_Always);
        
        ImPlot::SetNextLineStyle(ImVec4(0.2f, 0.7f, 1.0f, 1.0f), 2.5f);
        ImPlot::PlotLine("Utilization", ramHistory, 100);
        
        ImPlot::EndPlot();
    }
    
    // Restore style
    style.Colors[ImPlotCol_PlotBg] = originalPlotBg;
    style.Colors[ImPlotCol_FrameBg] = originalFrameBg;
    style.Colors[ImPlotCol_AxisGrid] = originalAxisGrid;
    
    // Legend/Info at bottom
    ImGui::Spacing();
    ImGui::SetCursorPosX(20);
    ImGui::TextColored(ImVec4(0.2f, 0.7f, 1.0f, 1.0f), "●");
    ImGui::SameLine();
    ImGui::Text("Utilization");
    
    // Show RAM percentage and total
    // ImGui::SetCursorPosX(590);
    // ImGui::SetCursorPosY(30);
    auto mem = GetMemoryInfo();
    float totalGB = static_cast<float>(mem.totalPhys) / (1024.0f * 1024.0f * 1024.0f);
    ImGui::SameLine(540);
    ImGui::Text("RAM Usage %.2f%%", mem.usagePercent);
    ImGui::SetCursorPosX(580);
    ImGui::SetCursorPosY(20);

    ImGui::Text("Total: %.1f GB", totalGB);
}