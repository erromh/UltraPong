cmake_minimum_required (VERSION 3.8)
project (UltraPong LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

include_directories(${CMAKE_SOURCE_DIR}/global_var)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message(STATUS "Shalom Linux")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message("Shalom win32")
else()
    message(STATUS "This is ${CMAKE_SYSTEM_NAME} speaking.")
endif()

add_subdirectory(src)

