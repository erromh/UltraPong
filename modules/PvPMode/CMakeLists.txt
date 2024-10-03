add_library(PvPMode 
	STATIC
		src/PvPMode.cpp
)

target_include_directories(PvPMode 
	PUBLIC 
		include
)

target_link_libraries(PvPMode
	PRIVATE 
		sfml-graphics
		Core
)


