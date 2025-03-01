file(GLOB VIEW_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library(views ${VIEW_SOURCES})

target_include_directories(views PUBLIC ${CMAKE_SOURCE_DIR}/src/views)

target_link_libraries(views PUBLIC sfml-graphics models)
