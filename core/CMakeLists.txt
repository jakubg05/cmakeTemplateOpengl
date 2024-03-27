cmake_minimum_required(VERSION 3.16)

project(templateCore)

add_library(core STATIC)

target_sources(core PRIVATE
"${CMAKE_CURRENT_SOURCE_DIR}/src/testcore.cpp"
)


target_compile_definitions(core PUBLIC RESOURCES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/resources/") # This is useful to get an ASSETS_PATH in your IDE during development but you should comment this if you compile a release version and uncomment the next line
#target_compile_definitions(core PUBLIC RESOURCES_PATH="./resources/") # Uncomment this line to setup the ASSETS_PATH macro to the final assets directory when you share the game and move the resources to the build folder


target_include_directories(core PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

