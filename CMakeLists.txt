cmake_minimum_required(VERSION 3.10)

project(3d-maze)

add_executable(
	${PROJECT_NAME} 
	${PROJECT_SOURCE_DIR}/Main.cpp
	${PROJECT_SOURCE_DIR}/glad.c
	${PROJECT_SOURCE_DIR}/src/GL-utils/ShaderSrc.cpp
	${PROJECT_SOURCE_DIR}/src/GL-utils/Shader.cpp
	${PROJECT_SOURCE_DIR}/src/GL-utils/VertexBuffer.cpp
	${PROJECT_SOURCE_DIR}/src/Engine.cpp
	${PROJECT_SOURCE_DIR}/src/EngineDraw.cpp
	${PROJECT_SOURCE_DIR}/src/EngineUpdate.cpp
	${PROJECT_SOURCE_DIR}/src/EngineHandleKeyInput.cpp
	${PROJECT_SOURCE_DIR}/src/EngineGenerateMaze.cpp
)

target_link_libraries(${PROJECT_NAME}  GL dl glfw)
