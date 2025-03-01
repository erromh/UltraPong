file(GLOB CONTROLLERS_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library(controllers ${CONTROLLERS_SOURCES})

target_include_directories(controllers PUBLIC 
    ${CMAKE_SOURCE_DIR}/src/controllers
    ${CMAKE_SOURCE_DIR}/src/states 
)

target_link_libraries(controllers PUBLIC states models views sfml-graphics)
