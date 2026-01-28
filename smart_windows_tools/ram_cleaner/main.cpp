#include "lib.hpp"

Icons g_icons;
fontStyles g_fontStyles;

int main() {
    // Initialize GLFW
    if (!glfwInit()) return -1;

    const char* glsl_version = "#version 330";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);  // Remove default title bar
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create window with your size
    GLFWwindow* window = glfwCreateWindow(729, 1037, "RAM Cleaner", NULL, NULL);

    if (!window) {
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    
#ifdef _WIN32
    // Apply rounded corners to the window
    ApplyWindowRounding(window, 30); // 50 = very rounded corners
#endif

    // Setup ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImPlot::CreateContext();  // Initialize ImPlot context
    // ImGuiIO& io = ImGui::GetIO();
    ImGui::StyleColorsDark();

    LoadAllIcons();
    // ImTextureID logoTex = (ImTextureID)(intptr_t)icons.logo;

    // Apply your background color to ImGui window
    ImGuiStyle& style = ImGui::GetStyle();
    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.047f, 0.055f, 0.122f, 1.0f);
    style.WindowPadding = ImVec2(0, 0);
    style.WindowBorderSize = 0.0f;

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
    set_fonts();
    // Your background color #0c0e1f
    float bg_color[4] = {0.047f, 0.055f, 0.122f, 1.0f};

    // ImFont* titleSmeiBold = io.Fonts->AddFontFromFileTTF("../../default_assests/inter/Inter_28pt-SemiBold.ttf", 28.0f);
    // ImFont* titleBold = io.Fonts->AddFontFromFileTTF("../../default_assests/inter/Inter_28pt-Bold.ttf", 28.0f);
    // ImFont* titleBlack = io.Fonts->AddFontFromFileTTF("../../default_assests/inter/Inter_24pt-Black.ttf", 24.0f);
    // ImFont* titleB = io.Fonts->AddFontFromFileTTF("../../default_assests/inter/Inter_18pt-Bold.ttf", 18.0f);
    // ImFont* titleRegular= io.Fonts->AddFontFromFileTTF("../../default_assests/inter/Inter_18pt-Regular.ttf", 18.0f);
    

    // if (titleBold == nullptr || titleSmeiBold == nullptr 
    //     || titleBlack == nullptr || titleB == nullptr 
    //     || titleRegular == nullptr) {
    //     titleBold = io.Fonts->Fonts[0]; // Fallback to default font
    // }
    // Main loop
    const double targetFrameRate = 30.0; // Target 30 FPS to reduce CPU usage
    const double targetFrameTime = 1.0 / targetFrameRate;

    while (!glfwWindowShouldClose(window)) {
        double frameStartTime = glfwGetTime();
        
        glfwPollEvents();

        // Update RAM data for graph
        UpdateRAMGraph();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Single fullscreen ImGui window (no title bar, no borders)
        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::SetNextWindowSize(ImVec2(729, 1037));
        ImGui::Begin("MainWindow", nullptr,
            ImGuiWindowFlags_NoResize |
            ImGuiWindowFlags_NoMove |
            ImGuiWindowFlags_NoCollapse |
            ImGuiWindowFlags_NoTitleBar |
            ImGuiWindowFlags_NoBringToFrontOnFocus);
        
        // Draw custom title bar
        DrawCustomTitleBar(window, "Memory Cleaner");
        
        // Your content goes here (below title bar at y=40)
        ImGui::SetCursorPosY(65);
        ImGui::SetCursorPosX(10);
        //draw first box
        DrawFirstBox(window, "Memory usage", ImGui::GetCursorPosY(), ImGui::GetCursorPosX());
        //draw second box
        ImGui::SetCursorPosY(415);
        ImGui::SetCursorPosX(10);
        DrawSecondBox(window, "Information", ImGui::GetCursorPosY(), ImGui::GetCursorPosX());
        //draw third box
        ImGui::SetCursorPosY(415);
        ImGui::SetCursorPosX(399);
        DrawThirdBox(window, ImGui::GetCursorPosY(), ImGui::GetCursorPosX());
        //draw fourth box
        ImGui::SetCursorPosY(687);
        ImGui::SetCursorPosX(10);
        DrawFourthBox(window, "Processes Name", ImGui::GetCursorPosY(), ImGui::GetCursorPosX());

        ImGui::End();
      //  ImGui::PopStyleVar(); // Match the PushStyleVar for WindowPadding
        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(bg_color[0], bg_color[1], bg_color[2], bg_color[3]);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
        
        // Limit frame rate to reduce CPU usage
        double frameEndTime = glfwGetTime();
        double frameTime = frameEndTime - frameStartTime;
        if (frameTime < targetFrameTime) {
            // Sleep for the remaining time to achieve target frame rate
            double sleepTime = targetFrameTime - frameTime;
            std::this_thread::sleep_for(std::chrono::milliseconds(
                static_cast<int>(sleepTime * 1000)));
        }
    }

    // Cleanup
    //glDeleteTextures(1, &myIconTexture);
    free_textures();
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImPlot::DestroyContext();  // Destroy ImPlot context before ImGui
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}