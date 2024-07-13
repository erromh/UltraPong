add_library(app2 "")

target_sources(app2
	
	PRIVATE
		MoveSquare.cpp

	PUBLIC
		${CMAKE_CURRENT_LIST_DIR}/MoveSquare.h
)

target_include_directories(app2
	PUBLIC
		${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(app2 
	PRIVATE
		sfml-graphics
)