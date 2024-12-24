add_executable(${PROJECT_NAME}
	main.cpp
 )

add_subdirectory(GameController)
add_subdirectory(GameMenu)

# add_subdirectory(modules/ExitWindow)

target_link_libraries(${PROJECT_NAME}
	PRIVATE
		sfml-graphics		
		Core
		GameController
		GameMenu
		ExitWindow
		Ball
		Players
		PlayerMoveUpCommand
		PlayerMoveDownCommand
		Command_Interface
)
