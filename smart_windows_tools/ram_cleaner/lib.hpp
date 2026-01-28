#ifndef RAM_CLEANER_LIB_HPP
#define RAM_CLEANER_LIB_HPP

#include "../../lib/imgui-master/imgui.h"
#include "../../lib/imgui-master/backends/imgui_impl_glfw.h"
#include "../../lib/imgui-master/backends/imgui_impl_opengl3.h"
#include "../../lib/glfw-3.4.bin.WIN64/include/GLFW/glfw3.h"
#ifdef _WIN32
#define GLFW_EXPOSE_NATIVE_WIN32
#endif
#include "../../lib/glfw-3.4.bin.WIN64/include/GLFW/glfw3native.h"
#include <iostream>
#include <cstdio>
#include <thread>
#include <chrono>

#include "../../lib/implot-master/implot.h"
#include "../../lib/implot-master/implot_internal.h"

#ifdef _WIN32
#include <windows.h>
#include <dwmapi.h>
//#pragma comment(lib, "dwmapi.lib")
#endif

#define s_height 1037
#define s_width 729

struct Icons {
    GLuint logo;
    GLuint github;
    GLuint exit;
    GLuint minimize;
};

struct RamInfo {
    std::string type;
    int speedMHz;
    int latencyNs;
    int channels;
    float voltageV;
    std::string formFactor;
    std::string manufacturer;
    std::string partNumber;
};


struct fontStyles {
    ImFont* Inter_18pt_Black;
    ImFont* Inter_18pt_Bold;
    ImFont* Inter_18pt_ExtraBold;
    ImFont* Inter_18pt_Medium;
    ImFont* Inter_18pt_Regular;
    ImFont* Inter_18pt_SemiBold;

    ImFont* Inter_24pt_Black;
    ImFont* Inter_24pt_Bold;
    ImFont* Inter_24pt_ExtraBold;
    ImFont* Inter_24pt_Medium;
    ImFont* Inter_24pt_Regular;
    ImFont* Inter_24pt_SemiBold;

    ImFont* Inter_28pt_Black;
    ImFont* Inter_28pt_Bold;
    ImFont* Inter_28pt_ExtraBold;
    ImFont* Inter_28pt_Medium;
    ImFont* Inter_28pt_Regular;
    ImFont* Inter_28pt_SemiBold;

};

extern Icons g_icons;
extern fontStyles g_fontStyles;

void DrawCustomTitleBar(GLFWwindow* window,  const char* title);
GLuint LoadTextureFromFile(const char* filename);
void LoadAllIcons();
void set_fonts();
void free_textures();
void DrawFirstBox(GLFWwindow* window, const char* title, float cursorPosY, float cursorPosX);


void SetMemoryInfo();
void DrawRAMGraph();
void UpdateRAMGraph();

void DrawSecondBox(GLFWwindow* window,const char* title, float cursorPosY, float cursorPosX);
void DrawThirdBox(GLFWwindow* window, float cursorPosY, float cursorPosX);
void DrawFourthBox(GLFWwindow* window,const char* title, float cursorPosY, float cursorPosX);



#ifdef _WIN32
// Apply rounded corners to a GLFW window
// Higher radius values create more rounded corners (e.g., 50 for very round, 10 for subtle)
inline void ApplyWindowRounding(GLFWwindow* window, int radius = 40) {
    HWND hwnd = glfwGetWin32Window(window);
    if (hwnd) {
        // Create rounded window region
        HRGN hRgn = CreateRoundRectRgn(0, 0, s_width + 1, s_height + 1, radius, radius);
        SetWindowRgn(hwnd, hRgn, TRUE);
        DeleteObject(hRgn);
        
        // Optional: Add DWM shadow effects (ensure proper types for MinGW)
        // DWM_MARGINS has same layout as MARGINS but is specific to DWM
        MARGINS margins = {1, 1, 1, 1}; // Subtle shadow
        HRESULT hr = DwmExtendFrameIntoClientArea(hwnd, &margins);
        if (SUCCEEDED(hr)) {
            // Shadow applied successfully
        }
    }
}
#endif

#endif