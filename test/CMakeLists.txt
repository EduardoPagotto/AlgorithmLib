cmake_minimum_required(VERSION 3.18.4)

PROJECT(Test)

#define os Lib's a serem usados
set (LibsAlgo ${CMAKE_SOURCE_DIR}/bin/libAlgorithm.a
			  -lpthread)

#define os includes
set (IncludesTest ${CMAKE_SOURCE_DIR}/algorithm)

add_executable (Test main.cpp)

target_link_libraries(Test ${LibsAlgo})
target_include_directories (Test PRIVATE ${IncludesTest})

INSTALL(FILES ${Test_BINARY_DIR}/Test DESTINATION bin)
