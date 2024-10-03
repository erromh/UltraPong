add_library(GameController STATIC
	src/GameController.cpp	
)

target_include_directories(GameController 
	PUBLIC
		include
)

target_link_libraries(GameController
	PRIVATE
		sfml-graphics
		Core

		Ball

		Players
		PlayerMoveUpCommand
		PlayerMoveDownCommand

		GameMenu
		Command_Interface
)

