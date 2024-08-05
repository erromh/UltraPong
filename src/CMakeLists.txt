add_executable(UitraPong main.cpp)

add_subdirectory(Ball)
add_subdirectory(Players)
add_subdirectory(Command_Interface)
add_subdirectory(PlayerMoveUpCommand)
add_subdirectory(PlayerMoveDownCommand)
add_subdirectory(Game)

target_link_libraries(UitraPong 
	PRIVATE
		sfml-graphics
		Ball
		Players
		Command_Interface
		PlayerMoveUpCommand
		PlayerMoveDownCommand
		Game
)


