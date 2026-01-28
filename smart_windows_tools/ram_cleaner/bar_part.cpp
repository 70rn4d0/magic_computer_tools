#include "lib.hpp"

// Window dragging state
static bool isDragging = false;
static ImVec2 dragOffset;

void DrawCustomTitleBar(GLFWwindow* window,  const char* title) {
    // ImGuiIO& io = ImGui::GetIO();
    ImVec2 mousePos = ImGui::GetMousePos();    // Title bar height
    float titleBarHeight = 70.0f;
    
    ImGui::SetCursorPos(ImVec2(10, 0));
    ImDrawList* drawList = ImGui::GetWindowDrawList();
    ImVec2 titleBarMin = ImGui::GetCursorScreenPos();
    ImVec2 titleBarMax = ImVec2(titleBarMin.x + s_width, titleBarMin.y + titleBarHeight);
    

    ImTextureID iconID = (ImTextureID)(intptr_t)g_icons.logo; 
    ImVec2 iconPos = ImVec2(titleBarMin.x + 15, titleBarMin.y + titleBarHeight / 2);
    ImVec2 iconSize(25.0f, 25.0f);
    ImVec2 p0(iconPos.x - iconSize.x*0.5f, iconPos.y - iconSize.y*0.6f);
    ImVec2 p1(p0.x + iconSize.x, p0.y + iconSize.y);
    drawList->AddImage(iconID, p0, p1);

    // Title text
    ImGui::SetCursorPos(ImVec2(44, titleBarHeight * 0.39f - ImGui::GetTextLineHeight() / 2));
    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
    ImGui::PushFont(g_fontStyles.Inter_24pt_Bold);
    ImGui::SetWindowFontScale(1.1f);
    ImGui::Text("%s", title);
    ImGui::PopFont();
    ImGui::PopStyleColor();
    
    // Buttons on the right
    float buttonSize = 32.0f;
    float buttonY = (titleBarHeight - buttonSize) / 2;
    float rightEdge = 729.0f;

    ImTextureID closeID = (ImTextureID)(intptr_t)g_icons.exit;
    ImVec2 closePos(rightEdge - buttonSize - 10, buttonY);
    ImVec2 closeIconCenter(closePos.x + buttonSize/2, closePos.y + buttonSize/2);
    ImVec2 closeIconSize(32.0f, 32.0f);
    ImVec2 closeP0(closeIconCenter.x - closeIconSize.x*0.5f, closeIconCenter.y - closeIconSize.y*0.5f);
    ImVec2 closeP1(closeP0.x + closeIconSize.x, closeP0.y + closeIconSize.y);
    drawList->AddImage(closeID, closeP0, closeP1);
    if (ImGui::IsMouseClicked(0)) {
        if (mousePos.x >= closePos.x && mousePos.x <= closePos.x + buttonSize &&
            mousePos.y >= closePos.y && mousePos.y <= closePos.y + buttonSize) {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }
    }

    ImTextureID minID = (ImTextureID)(intptr_t)g_icons.minimize;
    ImVec2 minPos(rightEdge - buttonSize - 52, buttonY);
    ImVec2 minIconCenter(minPos.x + buttonSize/2, minPos.y + buttonSize/2);
    ImVec2 minIconSize(32.0f, 32.0f);
    ImVec2 minP0(minIconCenter.x - minIconSize.x*0.5f, minIconCenter.y - minIconSize.y*0.5f);
    ImVec2 minP1(minP0.x + minIconSize.x, minP0.y + minIconSize.y);
    drawList->AddImage(minID, minP0, minP1);
    if (ImGui::IsMouseClicked(0)) {
        if (mousePos.x >= minPos.x && mousePos.x <= minPos.x + buttonSize &&
            mousePos.y >= minPos.y && mousePos.y <= minPos.y + buttonSize) {
            glfwIconifyWindow(window);
        }
    }

    ImTextureID githubID = (ImTextureID)(intptr_t)g_icons.github;
    ImVec2 githubPos(rightEdge - buttonSize - 94, buttonY);
    ImVec2 githubIconCenter(githubPos.x + buttonSize/2, githubPos.y + buttonSize/2);
    ImVec2 githubIconSize(32.0f, 32.0f);
    ImVec2 githubP0(githubIconCenter.x - githubIconSize.x*0.5f, githubIconCenter.y - githubIconSize.y*0.5f);
    ImVec2 githubP1(githubP0.x + githubIconSize.x, githubP0.y + githubIconSize.y);
    drawList->AddImage(githubID, githubP0, githubP1);
    if (ImGui::IsMouseClicked(0)) {
        if (mousePos.x >= githubPos.x && mousePos.x <= githubPos.x + buttonSize &&
            mousePos.y >= githubPos.y && mousePos.y <= githubPos.y + buttonSize) {
             system("start https://github.com/70rn4d0");
        }
    }
    
    // Handle window dragging
    static ImVec2 targetWindowPos;
    static ImVec2 currentWindowPos;
    static float dampingFactor = 0.7f; // Lower for more smoothing, higher for more responsive

    if (mousePos.y >= titleBarMin.y && mousePos.y < titleBarMax.y && 
        mousePos.x < rightEdge - (buttonSize * 3) - 30) {
        if (ImGui::IsMouseClicked(0)) {
            isDragging = true;
            int winX, winY;
            glfwGetWindowPos(window, &winX, &winY);
            dragOffset = ImVec2(mousePos.x - winX, mousePos.y - winY);
            currentWindowPos = ImVec2((float)winX, (float)winY);
            targetWindowPos = currentWindowPos;
        }
    }

    if (isDragging) {
        if (ImGui::IsMouseDown(0)) {
            // Calculate target position
            targetWindowPos = ImVec2(
                mousePos.x - dragOffset.x,
                mousePos.y - dragOffset.y
            );
            
            // Apply smooth damping
            currentWindowPos.x += (targetWindowPos.x - currentWindowPos.x) * dampingFactor;
            currentWindowPos.y += (targetWindowPos.y - currentWindowPos.y) * dampingFactor;
            
            // Only update if position changed enough
            static ImVec2 lastPos(-99999, -99999);
            if (abs(currentWindowPos.x - lastPos.x) > 0.5f || 
                abs(currentWindowPos.y - lastPos.y) > 0.5f) {
                glfwSetWindowPos(window, (int)currentWindowPos.x, (int)currentWindowPos.y);
                lastPos = currentWindowPos;
            }
        } else {
            isDragging = false;
        }
    }
    // Move cursor below title bar
    ImGui::SetCursorPos(ImVec2(0, titleBarHeight));

}