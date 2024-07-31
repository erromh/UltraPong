add_library(PlayerMoveUpCommand "")

target_sources(PlayerMoveUpCommand
        PRIVATE
            PlayerMoveUpCommand.cpp

        PUBLIC
		    "${CMAKE_CURRENT_LIST_DIR}/include/PlayerMoveUpCommand.h"
)

target_include_directories(PlayerMoveUpCommand
	PUBLIC
		${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(PlayerMoveUpCommand
	PRIVATE
		sfml-graphics
		Command_Interface
        Players
)