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

void Renderer::createInstance()
{
    std::cout << "Initializing Vulkan Instance..." << std::endl;

    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "vkEngine";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "vkEngine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_3;

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    ////// Validation Layers
#ifndef NDEBUG
    addLayer("VK_LAYER_KHRONOS_validation");
    createInfo.enabledLayerCount = enabledLayers.size();
    createInfo.ppEnabledLayerNames = enabledLayers.data();
#endif

    ////// Instance extensions
    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;

    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    std::cout << "GLFW requires " << glfwExtensionCount << " extensions:\n";
    for(int i = 0; i < glfwExtensionCount; ++i)
    {
        std::cout << "\t" << glfwExtensions[i] << std::endl;
    }

    createInfo.enabledExtensionCount = glfwExtensionCount;
    createInfo.ppEnabledExtensionNames = glfwExtensions;

    createInfo.enabledLayerCount = 0;

    VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);

    if( result == VK_SUCCESS )
    {
        std::cout << "Instance Created\n";
    }
    else
    {
        throw std::runtime_error("Failed to create vkInstance!");
    }

}

void Renderer::fetchSupportedInstanceExtensions()
{
    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

    std::cout << extensionCount << " Instance extensions supported\n";

    supportedExtensions.resize(extensionCount);

    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, supportedExtensions.data());

    for (const auto& extension : supportedExtensions) {
        std::cout << '\t' << extension.extensionName << '\n';
    }

}

void Renderer::fetchAvailableValidationLayers()
{
    uint32_t layerCount;
    vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

    std::cout << layerCount << " Validation Layers available\n";

    availableLayers.resize(layerCount);

    vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

    for (const auto& layer : availableLayers) {
        std::cout << '\t' << layer.layerName << '\n';
    }
}

void Renderer::mainWindowLoop()
{
    while( !glfwWindowShouldClose(window) )
    {
        glfwPollEvents();
    }
}

void Renderer::destroyVulkan()
{
    vkDestroyInstance(instance, nullptr);
}

void Renderer::destroyWindow()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Renderer::addLayer(const char* layer_name)
{
    std::cout << "Adding >>> " << layer_name << " <<< validation layer\n";
    enabledLayers.push_back(layer_name);
}