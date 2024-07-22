add_executable(UitraPong main.cpp)

add_subdirectory(Ball)
add_subdirectory(Players)
add_subdirectory(Command_Interface)

target_link_libraries(UitraPong 
	PRIVATE
		sfml-graphics
		Ball
		Players
		Command_Interface
)

#include_directories(${CMAKE_SOURCE_DIR}/Command_Interface)

