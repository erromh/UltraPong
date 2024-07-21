add_library(Ball "")

target_sources(Ball
	
	PRIVATE
		Ball.cpp

	PUBLIC
		"${CMAKE_CURRENT_LIST_DIR}/include/Ball.h"
)

target_include_directories(Ball
	PUBLIC
		${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(Ball
	PRIVATE
		sfml-graphics
)