# Compiler
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wformat
LIBS = -lglfw3 -lopengl32 -lgdi32 -ldwmapi

# Directories (use forward slashes for Make)
IMGUI_DIR = C:/Users/70rn4d0/Projects/c++/lib/imgui-master
GLFW_DIR = C:/Users/70rn4d0/Projects/c++/lib/glfw-3.4.bin.WIN64
IMPLOT_DIR = C:/Users/70rn4d0/Projects/c++/lib/implot-master
INCLUDES = -I$(IMGUI_DIR) -I$(IMGUI_DIR)/backends -I$(GLFW_DIR)/include -I$(IMPLOT_DIR)
LDFLAGS = -L$(GLFW_DIR)/lib-mingw-w64

# ImGui source files (ADDED imgui_demo.cpp!)
IMGUI_SOURCES = $(IMGUI_DIR)/imgui.cpp \
                $(IMGUI_DIR)/imgui_draw.cpp \
                $(IMGUI_DIR)/imgui_tables.cpp \
                $(IMGUI_DIR)/imgui_widgets.cpp \
                $(IMGUI_DIR)/imgui_demo.cpp \
                $(IMGUI_DIR)/backends/imgui_impl_glfw.cpp \
                $(IMGUI_DIR)/backends/imgui_impl_opengl3.cpp \
                $(IMPLOT_DIR)/implot.cpp \
                $(IMPLOT_DIR)/implot_items.cpp

# Your source files
SOURCES = main.cpp \
          load_texture.cpp \
          bar_part.cpp \
          content.cpp \
          DrawRamUsage.cpp \
          SetMemoryInfo.cpp

# Object files
OBJS = $(SOURCES:.cpp=.o) $(IMGUI_SOURCES:.cpp=.o)

# Output
TARGET = app.exe

# Build rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS) $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run