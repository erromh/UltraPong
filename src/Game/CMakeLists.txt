add_library(Game "")

target_sources(Game
	PRIVATE
		Game.cpp

	PUBLIC
		"${CMAKE_CURRENT_LIST_DIR}/include/Game.h"
)

target_include_directories(Game
	PUBLIC
		${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(Game
	PRIVATE
		sfml-graphics
		Players
		Command_Interface
		Ball
		PlayerMoveDownCommand
		PlayerMoveUpCommand
)