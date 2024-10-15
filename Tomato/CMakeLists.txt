set(SOURCE_FILES
        EntryPoint.h
        include/Tomato.h
        TomatoApplication.h
        TomatoApplication.cpp
)

add_library(Tomato STATIC ${SOURCE_FILES})

target_compile_definitions(Tomato
		PRIVATE
			TOMATO_LIB
		PUBLIC
			$<$<CONFIG:Debug>:TOMATO_DEBUG=2>
			$<$<CONFIG:RelWithDebInfo>:TOMATO_DEBUG=1>
)

if(MSVC)
        target_compile_definitions(Tomato PUBLIC TOMATO_MS_COMPILER)
endif()

target_precompile_headers(Tomato PRIVATE pch.h)