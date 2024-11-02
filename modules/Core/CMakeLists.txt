add_library(Core 
	STATIC
		src/GameFactory.cpp 
		src/GameStrategy.cpp
)

target_include_directories(Core 
	PUBLIC
		include
)

target_link_libraries(Core
	PUBLIC 
		sfml-graphics 

		Players
		Ball
		PvPMode
		BotMode
		PlayerMoveDownCommand
		PlayerMoveUpCommand
		Command_Interface
		CollisionHandler
)
