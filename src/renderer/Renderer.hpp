#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

class Renderer
{
public:
    void initWindow(int windowWidth = 800, int windowHeight = 600);
    void initVulkan();
    void mainWindowLoop();
    void destroyWindow();

private:
    GLFWwindow* window;
};