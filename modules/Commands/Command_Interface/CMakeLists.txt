add_library(Command_Interface INTERFACE)

target_include_directories(Command_Interface 
	INTERFACE 
		${CMAKE_CURRENT_SOURCE_DIR}/include
)
