add_library(CollisionHandler
	STATIC
		src/CollisionHandler.cpp
)

target_include_directories(CollisionHandler
	PUBLIC 
		include
)

target_link_libraries(CollisionHandler
	PRIVATE 
		sfml-graphics
		Players
		PvPMode
		Ball
)