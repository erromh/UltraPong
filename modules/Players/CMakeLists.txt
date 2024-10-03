add_library(Players STATIC 
	src/Players.cpp
)

target_include_directories(Players 
	PUBLIC 
		include
)

target_link_libraries(Players 
	PRIVATE 
		sfml-graphics
)
