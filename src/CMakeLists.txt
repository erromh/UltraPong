add_executable(UitraPong main.cpp)

add_subdirectory(Ball)

target_link_libraries(UitraPong 
	PRIVATE
		sfml-graphics
		Ball
)