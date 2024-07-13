add_executable(UitraPong main.cpp)

add_subdirectory(app2)


#target_link_libraries(UltraPong PRIVATE )

target_link_libraries(UitraPong 
	PRIVATE
		sfml-graphics
		app2
)