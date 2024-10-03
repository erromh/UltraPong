add_library(Ball 
	STATIC
		src/Ball.cpp
)

target_include_directories(Ball 
	PUBLIC 
		include
)

target_link_libraries(Ball 
	PRIVATE 
		sfml-graphics
)