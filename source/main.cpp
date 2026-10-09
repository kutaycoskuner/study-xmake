#include <iostream>
#include <string>

#include "my_functions.h"
#include <hello.hpp>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <glad/glad.h>      // must come before glfw3.h: it provides the OpenGL declarations
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>


void error_callback(int error, const char* description)
{
    std::cerr << "GLFW Error " << error << ": " << description << std::endl;
}


int main()
{
    std::cout << "hello from xmake" << std::endl;
    printMessage();
    hello::sayHello();
    std::cout << DATA_DIR << std::endl;

     // Assimp: load the test model from DATA_DIR
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(DATA_DIR + std::string("test.stl"),
                                             aiProcess_Triangulate | aiProcess_FlipUVs);
    if (!scene)
    {
        std::cerr << "Assimp import failed: " << importer.GetErrorString() << std::endl;
        return -1;
    }
    std::cout << "Assimp import succeeded, meshes: " << scene->mNumMeshes << std::endl;

    // GLFW: open a window and clear it each frame
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(640, 480, "xmake OpenGL test", nullptr, nullptr);
    if (!window)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);    // vsync

    // GLAD: load OpenGL 3.3 function pointers, needs a current context
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
    {
        std::cerr << "Failed to load OpenGL with GLAD" << std::endl;
        return -1;
    }
    std::cout << "OpenGL " << reinterpret_cast<const char*>(glGetString(GL_VERSION)) << std::endl;

    // ImGui: context, then the two backends
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    float clear_color[3] = { 0.2f, 0.3f, 0.3f };

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        // describe this frame's UI
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        ImGui::Begin("xmake test");
        ImGui::Text("Meshes in test.stl: %u", scene->mNumMeshes);
        ImGui::ColorEdit3("clear color", clear_color);
        ImGui::End();
        ImGui::Render();

        // draw: clear, then the UI on top
        glClearColor(clear_color[0], clear_color[1], clear_color[2], 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
