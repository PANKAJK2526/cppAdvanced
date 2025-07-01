add_library(calculator calculator.cpp)

target_include_directories(
	calculator 
	PUBLIC 
       		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
		$<INSTALL_INTERFACE:include>	
	)

install(TARGETS calculator
	EXPORT calculatorTargets
	ARCHIVE DESTINATION lib
	LIBRARY DESTINATION lib
	RUNTIME DESTINATION bin)

install(FILES calculator.h DESTINATION include)

install(EXPORT calculatorTargets
	FILE calculatorTargets.cmake
	NAMESPACE calc::
	DESTINATION lib/cmake/calculator)

