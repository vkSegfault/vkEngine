#include <vector>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

class Renderer
{
public:
    void initWindow(int windowWidth = 800, int windowHeight = 600);
    void createInstance();
    void fetchSupportedInstanceExtensions();
    void fetchAvailableValidationLayers();
    void mainWindowLoop();
    void destroyVulkan();
    void destroyWindow();

private:
    GLFWwindow* window;
    VkInstance instance;
    std::vector<VkExtensionProperties> supportedExtensions;
    std::vector<VkLayerProperties> availableLayers;
    std::vector<const char*> enabledLayers;

    void addLayer(const char* layer_name);
};