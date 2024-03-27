# this is a custom template cmake project derived from https://github.com/meemknight/cmakeSetup

cmake_minimum_required(VERSION 3.16)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>") #we want to use the static runtime

project(cmakeTemplate)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
set(ONLY_LIBS ON)								#glew wont generate executable targets
add_subdirectory(thirdparty/glfw-3.3.2)			#window oppener
add_subdirectory(thirdparty/glew-cmake)			#opengl loader
add_subdirectory(thirdparty/stb_image)			#loading immaged
add_subdirectory(thirdparty/stb_truetype)		#loading ttf files
add_subdirectory(thirdparty/glm)				#math
add_subdirectory(thirdparty/imgui-docking)		#ui

add_subdirectory(core)


# Define APP_SOURCES to be a list of all the source files for my game 
file(GLOB_RECURSE APP_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/app/src/*.cpp")

set(EXECUTABLE_NAME "cmakeMain") # the name of the final executable
add_executable("${EXECUTABLE_NAME}")

set_property(TARGET "${EXECUTABLE_NAME}" PROPERTY CXX_STANDARD 17)

target_sources("${EXECUTABLE_NAME}" PRIVATE ${APP_SOURCES} )


if(MSVC) # If using the VS compiler...

	target_compile_definitions("${EXECUTABLE_NAME}" PUBLIC _CRT_SECURE_NO_WARNINGS)

	#remove console
	#set_target_properties("${EXECUTABLE_NAME}" PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
	
	set_property(TARGET "${EXECUTABLE_NAME}" PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

endif()


target_include_directories("${EXECUTABLE_NAME}" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/app/include/")


target_link_libraries("${EXECUTABLE_NAME}" PUBLIC glm glfw libglew_static
	stb_image stb_truetype imgui core)
