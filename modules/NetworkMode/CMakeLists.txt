add_library(NetworkMode STATIC 
	src/NetworkMode.cpp	
)

include_directories(include)

target_link_libraries(NetworkMode PRIVATE Core)