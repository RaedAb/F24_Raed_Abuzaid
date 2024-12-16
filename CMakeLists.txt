cmake_minimum_required(VERSION 3.24)

project(F24_Raed_Abuzaid)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(stbi)
add_subdirectory(glad)
add_subdirectory(glfw)
add_subdirectory(Tomato)
add_subdirectory(MyGame)

set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT MyGame)

file(COPY Tomato/TomatoAssets DESTINATION ${CMAKE_BINARY_DIR}/Tomato/)
file(COPY MyGame/Assets DESTINATION ${CMAKE_BINARY_DIR}/MyGame/)
