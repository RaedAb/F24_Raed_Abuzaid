set(SOURCE_FILES
    EntryPoint.h
    include/Tomato.h
    TomatoApplication.h
    TomatoApplication.cpp
    Image.h
    Image.cpp
    ImageImpl.h
    codeOpenGL/OpenGLImage.h
    codeOpenGL/OpenGLImage.cpp
    Shaders.h
    Shaders.cpp
    ShadersImpl.h
    codeOpenGL/OpenGLShaders.h
    codeOpenGL/OpenGLShaders.cpp
    Renderer.h
    Renderer.cpp
    RendererImpl.h
    codeOpenGL/OpenGLRenderer.h
    codeOpenGL/OpenGLRenderer.cpp
    TomatoWindow.h
    TomatoWindow.cpp
    WindowImpl.h
    codeGLFW/WindowGLFW.h
    codeGLFW/WindowGLFW.cpp
    KeyCodes.h
    TomatoEvents.h
    TomatoEvents.cpp
    TomatoUtilities.h
    Unit.h
    Unit.cpp
)

add_library(Tomato SHARED ${SOURCE_FILES})

target_compile_definitions(Tomato
		PRIVATE
			TOMATO_LIB
		PUBLIC
			$<$<CONFIG:Debug>:TOMATO_DEBUG=2>
			$<$<CONFIG:RelWithDebInfo>:TOMATO_DEBUG=1>
            TOMATO_OPENGL_STBI
            TOMATO_GLFW
)

if(MSVC)
        target_compile_definitions(Tomato PUBLIC TOMATO_MS_COMPILER)
endif()

target_precompile_headers(Tomato PRIVATE pch.h)

find_package(OpenGL REQUIRED)
target_link_libraries(Tomato glfw glad stbi)

include_directories("../glad/include")
include_directories("../glfw/include")
include_directories("../stbi")
include_directories("../Tomato/")
