add_library(Players "")

target_sources(Players
	
	PRIVATE
		Players.cpp

	PUBLIC
		"${CMAKE_CURRENT_LIST_DIR}/include/Players.h"
)

target_include_directories(Players
	PUBLIC
		${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(Players
	PRIVATE
		sfml-graphics
)