#include "lib.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "../../lib/stb_image.h"

GLuint LoadTextureFromFile(const char* filename) {
    //stbi_set_flip_vertically_on_load(true); // flip if image appears upside down
    int width, height, channels;
    unsigned char* data = stbi_load(filename, &width, &height, &channels, 4);
    if (!data) {
        printf("Failed to load image '%s'\n", filename);
        return 0;
    }

    GLuint tex;
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // upload RGBA data
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, data);

    stbi_image_free(data);
    return tex;
}



void LoadAllIcons() {
    g_icons.logo = LoadTextureFromFile("icon/logo.png");
    g_icons.minimize = LoadTextureFromFile("icon/minus/m64.png");
    g_icons.exit = LoadTextureFromFile("icon/close/E64.png");
    g_icons.github = LoadTextureFromFile("icon/github/G64.png");

    if (!g_icons.logo || !g_icons.minimize || !g_icons.exit || !g_icons.github)
        std::cerr << "⚠️ Some icons failed to load!\n";
}


void set_fonts() {
    ImGuiIO& io = ImGui::GetIO();

    g_fontStyles.Inter_18pt_Black = io.Fonts->AddFontFromFileTTF("../../default_assests/inter/Inter_18pt-Black.ttf", 18.0f);
    g_fontStyles.Inter_18pt_Bold = io.Fonts->AddFontFromFileTTF("../../default_assests/inter/Inter_18pt-Bold.ttf", 18.0f);
    g_fontStyles.Inter_18pt_ExtraBold = io.Fonts->AddFontFromFileTTF("../../default_assests/inter/Inter_18pt-ExtraBold.ttf", 18.0f);
    g_fontStyles.Inter_18pt_Medium = io.Fonts->AddFontFromFileTTF("../../default_assests/inter/Inter_18pt-Medium.ttf", 18.0f);
    g_fontStyles.Inter_18pt_Regular = io.Fonts->AddFontFromFileTTF("../../default_assests/inter/Inter_18pt-Regular.ttf", 18.0f);
    g_fontStyles.Inter_18pt_SemiBold = io.Fonts->AddFontFromFileTTF("../../default_assests/inter/Inter_18pt-SemiBold.ttf", 18.0f);
    g_fontStyles.Inter_24pt_Black = io.Fonts->AddFontFromFileTTF("../../default_assests/inter/Inter_24pt-Black.ttf", 24.0f);
    g_fontStyles.Inter_24pt_Bold = io.Fonts->AddFontFromFileTTF("../../default_assests/inter/Inter_24pt-Bold.ttf", 24.0f);
    g_fontStyles.Inter_24pt_ExtraBold = io.Fonts->AddFontFromFileTTF("../../default_assests/inter/Inter_24pt-ExtraBold.ttf", 24.0f);
    g_fontStyles.Inter_24pt_Medium = io.Fonts->AddFontFromFileTTF("../../default_assests/inter/Inter_24pt-Medium.ttf", 24.0f);
    g_fontStyles.Inter_24pt_Regular = io.Fonts->AddFontFromFileTTF("../../default_assests/inter/Inter_24pt-Regular.ttf", 24.0f);
    g_fontStyles.Inter_24pt_SemiBold = io.Fonts->AddFontFromFileTTF("../../default_assests/inter/Inter_24pt-SemiBold.ttf", 24.0f);
    g_fontStyles.Inter_28pt_Black = io.Fonts->AddFontFromFileTTF("../../default_assests/inter/Inter_28pt-Black.ttf", 28.0f);
    g_fontStyles.Inter_28pt_Bold = io.Fonts->AddFontFromFileTTF("../../default_assests/inter/Inter_28pt-Bold.ttf", 28.0f);
    g_fontStyles.Inter_28pt_ExtraBold = io.Fonts->AddFontFromFileTTF("../../default_assests/inter/Inter_28pt-ExtraBold.ttf", 28.0f);
    g_fontStyles.Inter_28pt_Medium = io.Fonts->AddFontFromFileTTF("../../default_assests/inter/Inter_28pt-Medium.ttf", 28.0f);
    g_fontStyles.Inter_28pt_Regular = io.Fonts->AddFontFromFileTTF("../../default_assests/inter/Inter_28pt-Regular.ttf", 28.0f);
    g_fontStyles.Inter_28pt_SemiBold = io.Fonts->AddFontFromFileTTF("../../default_assests/inter/Inter_28pt-SemiBold.ttf", 28.0f);


    if (!g_fontStyles.Inter_18pt_Black || !g_fontStyles.Inter_18pt_Bold || !g_fontStyles.Inter_18pt_ExtraBold ||
        !g_fontStyles.Inter_18pt_Medium || !g_fontStyles.Inter_18pt_Regular || !g_fontStyles.Inter_18pt_SemiBold ||
        !g_fontStyles.Inter_24pt_Black || !g_fontStyles.Inter_24pt_Bold || !g_fontStyles.Inter_24pt_ExtraBold ||
        !g_fontStyles.Inter_24pt_Medium || !g_fontStyles.Inter_24pt_Regular || !g_fontStyles.Inter_24pt_SemiBold ||
        !g_fontStyles.Inter_28pt_Black || !g_fontStyles.Inter_28pt_Bold || !g_fontStyles.Inter_28pt_ExtraBold ||
        !g_fontStyles.Inter_28pt_Medium || !g_fontStyles.Inter_28pt_Regular || !g_fontStyles.Inter_28pt_SemiBold) {
        std::cerr << "⚠️ Some fonts failed to load!\n";
    }


}



void free_textures() {
    glDeleteTextures(1, &g_icons.logo);
    glDeleteTextures(1, &g_icons.minimize);
    glDeleteTextures(1, &g_icons.exit);
    glDeleteTextures(1, &g_icons.github);

    // Free font resources
    ImGui::GetIO().Fonts->Clear();

}