add_library(PlayerMoveDownCommand "")

target_sources(PlayerMoveDownCommand
      PRIVATE
            PlayerMoveDownCommand.cpp

        PUBLIC
		    "${CMAKE_CURRENT_LIST_DIR}/include/PlayerMoveDownCommand.h"
)

target_include_directories(PlayerMoveDownCommand
	PUBLIC
		${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(PlayerMoveDownCommand
	PRIVATE
		sfml-graphics
		Command_Interface
        Players
)