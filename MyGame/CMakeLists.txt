add_executable(MyGame MyGame.cpp)

target_include_directories(MyGame PRIVATE ../Tomato/include)

target_link_libraries(MyGame Tomato)
