add_executable(UitraPong main.cpp)

add_subdirectory(Ball)
add_subdirectory(Players)

target_link_libraries(UitraPong 
	PRIVATE
		sfml-graphics
		Ball
		Players
)