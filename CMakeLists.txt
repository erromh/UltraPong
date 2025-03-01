cmake_minimum_required (VERSION 3.8)
project (UltraPong LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

add_definitions(-DPROJECT_ROOT_DIR=\"${CMAKE_SOURCE_DIR}\")

include(FetchContent)
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.0
)
FetchContent_MakeAvailable(SFML)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message(STATUS "Shalom Linux")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message("Shalom win32")
else()
    message(STATUS "This is ${CMAKE_SYSTEM_NAME} speaking.")
endif()
 
add_subdirectory(src)
add_executable(UltraPong src/main.cpp)

target_link_libraries(UltraPong 
    PUBLIC 
        sfml-system 
        sfml-window 
        sfml-graphics 
        sfml-audio
        
        controllers
        models
        states
        views
)