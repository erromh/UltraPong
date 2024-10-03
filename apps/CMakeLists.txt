add_executable(${PROJECT_NAME}
	main.cpp
)

add_subdirectory(GameController)
add_subdirectory(GameMenu)

target_link_libraries(${PROJECT_NAME}
	PRIVATE
		sfml-graphics
		
		Core
		GameController
		GameMenu

		Ball

		Players
		PlayerMoveUpCommand
		PlayerMoveDownCommand

		Command_Interface
)
