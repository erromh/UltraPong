add_library(ExitWindow 
	STATIC
		src/ExitWindow.cpp	
)

include_directories(GameMenu)

target_include_directories(ExitWindow 
	PUBLIC
		include

	PRIVATE
		GameMenu
)

target_link_libraries(ExitWindow
	PRIVATE
		sfml-graphics
		GameMenu
)

