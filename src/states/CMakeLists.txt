file(GLOB STATES_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library(states ${STATES_SOURCES})

target_include_directories(states PUBLIC ${CMAKE_SOURCE_DIR}/src/states)

target_link_libraries(states PUBLIC sfml-graphics controllers)