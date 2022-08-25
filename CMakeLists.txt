cmake_minimum_required(VERSION 3.11)

add_subdirectory(include/glad)
add_custom_target(
	glad_lib
	COMMAND cd include/glad && make
)

include_directories(include/glfw/include)
include_directories(include/glm)

if(${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Windows")
	set(CMAKE_CXX_FLAGS "-mwindows -O2 -static-libgcc -static-libstdc++")
else()
	set(CMAKE_CXX_FLAGS "-O2 -static-libgcc -static-libstdc++")
endif()

project(3d-maze)

find_package(OpenGL REQUIRED)

add_executable(
	${PROJECT_NAME} 
	${PROJECT_SOURCE_DIR}/Main.cpp
	${PROJECT_SOURCE_DIR}/src/GL-utils/ShaderSrc.cpp
	${PROJECT_SOURCE_DIR}/src/GL-utils/Shader.cpp
	${PROJECT_SOURCE_DIR}/src/GL-utils/VertexBuffer.cpp
	${PROJECT_SOURCE_DIR}/src/Engine.cpp
	${PROJECT_SOURCE_DIR}/src/EngineDraw.cpp
	${PROJECT_SOURCE_DIR}/src/EngineUpdate.cpp
	${PROJECT_SOURCE_DIR}/src/EngineHandleKeyInput.cpp
	${PROJECT_SOURCE_DIR}/src/EngineGenerateMaze.cpp
	${PROJECT_SOURCE_DIR}/src/EngineHandleWindowResize.cpp
)

add_dependencies(${PROJECT_NAME} glad_lib)
target_link_libraries(${PROJECT_NAME} ${CMAKE_BINARY_DIR}/include/glad/libglad.a)
target_link_libraries(${PROJECT_NAME} OpenGL::GL glfw3)
