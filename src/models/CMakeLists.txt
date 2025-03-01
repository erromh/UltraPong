file(GLOB MODELS_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library(models ${MODELS_SOURCES})

target_include_directories(models PUBLIC ${CMAKE_SOURCE_DIR}/src/models)

target_link_libraries(models  PUBLIC sfml-graphics)