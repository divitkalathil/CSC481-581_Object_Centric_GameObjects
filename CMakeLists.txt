# CMakeLists.txt

cmake_minimum_required(VERSION 3.10)

project(ObjectCentricDemo)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Use pkg-config to find SDL3. This is the most reliable method on macOS.
find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL3 REQUIRED IMPORTED_TARGET sdl3)

# Create the executable from your source files
add_executable(
    ObjectCentricDemo
    src/main.cpp
    src/GameObject.cpp
    src/Rectangle.cpp
    # TODO: Add your Circle.cpp file here when you create it!
    # src/Circle.cpp
)

# Link the SDL3 library using the target found by pkg-config
# This automatically handles include directories and linker flags.
target_link_libraries(ObjectCentricDemo PRIVATE PkgConfig::SDL3)

# Also add our own src directory to the include path for cleaner #includes
target_include_directories(ObjectCentricDemo PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)