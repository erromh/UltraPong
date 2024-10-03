add_library(PlayerMoveDownCommand 
	STATIC
		src/PlayerMoveDownCommand.cpp
)

target_include_directories(PlayerMoveDownCommand
	PUBLIC 
		include
)

target_link_libraries(PlayerMoveDownCommand 
	PRIVATE 
		sfml-graphics
		Players
		Command_Interface
)