add_library(GameMenu 
	STATIC
		src/GameMenu.cpp
)

target_include_directories(GameMenu
	PUBLIC 
		include
)

target_link_libraries(GameMenu
	PRIVATE 
		sfml-graphics
		ExitWindow
)