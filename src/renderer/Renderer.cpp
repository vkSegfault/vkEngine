#include "Renderer.hpp"

#include <iostream>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <vec4.hpp>
#include <mat4x4.hpp>

void Renderer::initWindow(int windowWidth, int windowHeight)
{
    // to init GLFW with Wayland support we need to compile it first with proper flag
    // https://github.com/glfw/glfw/issues/2558#issuecomment-2143539138

    glfwInit();
    std::cout << glfwGetVersionString() << std::endl;

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  if (glfwPlatformSupported(GLFW_PLATFORM_WAYLAND)) {
    std::cout << "Wayland Supported" << std::endl;
    glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_WAYLAND);
  } else {
    std::cout << "No Wayland Support, fallback to X11" << std::endl;
  }

    window = glfwCreateWindow(windowWidth, windowHeight, "vkEngine window", nullptr, nullptr);
}

void Renderer::initVulkan()
{
    std::cout << "Init" << std::endl;

    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

    std::cout << extensionCount << " extensions supported\n";

    glm::mat4 matrix;
    glm::vec4 vec;
    auto test = matrix * vec;
}

void Renderer::mainWindowLoop()
{
    while( !glfwWindowShouldClose(window) )
    {
        glfwPollEvents();
    }
}

void Renderer::destroyWindow()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}
