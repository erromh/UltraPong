add_library(BotMode
	STATIC
		src/BotMode.cpp
)

target_include_directories(BotMode 
	PUBLIC 
		include
)

target_link_libraries(BotMode 
	PRIVATE 
		sfml-graphics
		Core
)


