cmake_minimum_required (VERSION 3.11)
project (UltraPong LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(IMGUI_SFML_FIND_SFML OFF)
set(IMGUI_DIR ${CMAKE_BINARY_DIR}/_deps/imgui-src)

message("CMAKE_BINARY_DIR - "${CMAKE_BINARY_DIR})

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

add_definitions(-DPROJECT_ROOT_DIR=\"${CMAKE_SOURCE_DIR}\")

include(FetchContent)
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.0
)
FetchContent_MakeAvailable(SFML)

FetchContent_Declare(
    TGUI
    GIT_REPOSITORY https://github.com/texus/TGUI.git
    GIT_TAG 1.x
)
FetchContent_MakeAvailable(TGUI)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message(STATUS "Shalom Linux")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message("Shalom win32")
else()
    message(STATUS "This is ${CMAKE_SYSTEM_NAME} speaking.")
endif()
 
if (WIN32)
    set(BOOST_ROOT "D:/Boost/boost_1_82_0")
elseif (UNIX)
    set(BOOST_ROOT "/usr/local/boost")
endif()

find_package(Boost 1.82 REQUIRED COMPONENTS system)

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

    PRIVATE
        Boost::system
        TGUI::TGUI
)
