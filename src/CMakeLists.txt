cmake_minimum_required(VERSION 3.28)

project(Engine
        VERSION 0.1
        DESCRIPTION "Game Engine for strategy games")

add_subdirectory("renderer")

set( EXTERNAL_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../external" )

add_executable(Engine main.cpp)
target_include_directories( ${PROJECT_NAME} PUBLIC "renderer")

target_link_directories( ${PROJECT_NAME} PUBLIC 
    "${EXTERNAL_PATH}/vulkan/${VULKAN_VER}/lib"
)

target_link_libraries( ${PROJECT_NAME} Renderer "dl" "pthread" "libvulkan.so" "X11" "Xxf86vm" "Xrandr" "Xi" )