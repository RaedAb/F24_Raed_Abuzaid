add_executable(MyGame MyGame.cpp MovementHandler.cpp CollisionHandler.cpp InputHandler.cpp)

target_include_directories(MyGame PRIVATE ../Tomato/include)

target_link_libraries(MyGame Tomato)
