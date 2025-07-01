cmake_minimum_required(VERSION 3.14)
project(CppTddProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(ENABLE_TESTS "Enable building tests" ON)

add_subdirectory(src)

if(ENABLE_TESTS)
	enable_testing()

	include(FetchContent)
	FetchContent_Declare(
		googletest
		URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
	)
	FetchContent_MakeAvailable(googletest)

	add_subdirectory(test)
endif()

include(CMakePackageConfigHelpers)

configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Config.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/calcConfig.cmake"
    INSTALL_DESTINATION lib/cmake/calculator
)

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/calcConfigVersion.cmake"
    VERSION 1.0.0
    COMPATIBILITY AnyNewerVersion
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/calcConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/calcConfigVersion.cmake"
    DESTINATION lib/cmake/calculator
)


