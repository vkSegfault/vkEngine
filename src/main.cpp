#include <iostream>
#include "Renderer.hpp"

int main()
{
    std::cout << "vkEngine" << std::endl;
    Renderer r;

    // create and initialize
    r.initWindow(800, 600);
    r.createInstance();
    r.fetchSupportedInstanceExtensions();

    // process main loop
    r.mainWindowLoop();

    // terminate and cleanup
    r.destroyVulkan();
    r.destroyWindow();
    return 0;
}