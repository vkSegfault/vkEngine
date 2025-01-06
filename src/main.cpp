#include <iostream>
#include "Renderer.hpp"

int main()
{
    std::cout << "vkEngine" << std::endl;
    Renderer r;
    r.initWindow(800, 600);
    r.initVulkan();
    r.mainWindowLoop();
    r.destroyWindow();
    return 0;
}