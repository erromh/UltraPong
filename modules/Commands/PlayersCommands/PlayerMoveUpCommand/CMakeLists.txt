add_library(PlayerMoveUpCommand STATIC
	src/PlayerMoveUpCommand.cpp
)

target_include_directories(PlayerMoveUpCommand
	PUBLIC 
		include
)

target_link_libraries(PlayerMoveUpCommand 
	PRIVATE 
		sfml-graphics
		Players
		Command_Interface
)