cmake_minimum_required (VERSION 3.8)
project (UltraPong LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

add_definitions(-DPROJECT_ROOT_DIR=\"${CMAKE_SOURCE_DIR}\")

include(FetchContent)
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
)
FetchContent_Declare(
    imgui
    GIT_REPOSITORY https://github.com/ocornut/imgui.git
    GIT_TAG v1.91.1
)
FetchContent_MakeAvailable(imgui SFML)

include_directories(${CMAKE_SOURCE_DIR}/global_var)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message(STATUS "Shalom Linux")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message("Shalom win32")
else()
    message(STATUS "This is ${CMAKE_SYSTEM_NAME} speaking.")
endif()
   
add_subdirectory(modules/Ball)
add_subdirectory(modules/Players)
add_subdirectory(modules/Commands)

add_subdirectory(modules/Core)
add_subdirectory(modules/PvPMode)
add_subdirectory(modules/NetworkMode)
add_subdirectory(modules/BotMode)

add_subdirectory(apps)

