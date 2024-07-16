add_executable(UitraPong main.cpp)

add_subdirectory(app2)
add_subdirectory(Ball)

target_link_libraries(UitraPong 
	PRIVATE
		sfml-graphics
		app2
		Ball
)