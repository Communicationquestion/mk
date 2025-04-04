#pragma once
#include <type_traits>

#define USE_RENDERER_OPENGL
// #define USE_RENDERER_DX
// #define USE_RENDERER_VULKAN

#ifdef USE_RENDERER_OPENGL
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <imgui/imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#endif

#ifdef USE_RENDERER_VULKAN
#endif

#ifdef USE_RENDERER_DX
#endif
struct opengl {};
struct dx {};
struct vulkan {};
#include <MkGui/customcontrol.h>
#include <MkGui/layout.h>
#include <optional>
#include <string>
#include <tools/tools.h>

template <typename Rendereren, typename... Args>
struct Rendererengine {};

template <typename... N>
struct Rendererengine<vulkan, N...> {};
template <typename... N>
struct Rendererengine<opengl, N...> {
    std::optional<std::string> init() {
        if (!glfwInit()) {
            return "Failed to initialize GLFW";
        }
        // 设置GLFW窗口属性
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        GLFWwindow* window = glfwCreateWindow(1280, 720, "Simple IMGUI Program", NULL, NULL);
        if (!window) {
            glfwTerminate();
            return "Failed to create GLFW window";
        }
        glfwMakeContextCurrent(window);

        if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
            glfwDestroyWindow(window);
            glfwTerminate();
            return "Failed to initialize GLAD";
        }

        // ImGui 初始化代码...
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        (void) io;
        ImGui::StyleColorsDark();

        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 330");

        // 主循环...
        while (!glfwWindowShouldClose(window)) {
            glfwPollEvents();

            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            // 获取当前窗口的尺寸
            int display_w, display_h;
            glfwGetFramebufferSize(window, &display_w, &display_h);
            ImVec2 window_size = ImVec2(static_cast<float>(display_w), static_cast<float>(display_h));

            // 设置下一个窗口的位置为 (0, 0)，即左上角
            ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f));
            // 设置下一个窗口的大小为整个窗口的尺寸
            ImGui::SetNextWindowSize(window_size);
            // 使用 ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize |
            // ImGuiWindowFlags_NoCollapse 来禁止移动、调整大小和折叠窗口
            ImGui::Begin("Main Window", nullptr,
                ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);

            // 在这里添加你的 ImGui 控件

            ImGui::End();

            ImGui::Render();
            glViewport(0, 0, display_w, display_h);
            glClear(GL_COLOR_BUFFER_BIT);
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

            glfwSwapBuffers(window);
        }
        // 清理资源...
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();

        glfwDestroyWindow(window);
        glfwTerminate();
        // 如果一切顺利，则返回 std::nullopt 表示无错误
        return std::nullopt;
    }
};
template <typename... N>
struct Rendererengine<dx, N...> {};

template <typename Rendereren = opengl, typename... Args>
class windowui {
public:
    explicit windowui() {}
    std::optional<std::string> test() {
        return std::nullopt;
    }

    std::optional<std::string> run() {
        Rendererengine<Rendereren, Args...> opengl_ui;

        lookerr<std::string>(opengl_ui.init());

        return std::nullopt;
    }

private:
    // LayoutManager m_Winui_layout;
};
