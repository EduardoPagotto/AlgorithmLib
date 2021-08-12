cmake_minimum_required(VERSION 3.18.4)

PROJECT(heapTest)

#define os Lib's a serem usados
set (LibsAlgo ${CMAKE_SOURCE_DIR}/bin/libAlgorithm.a
			  -lpthread)

#define os includes
set (IncludesTest ${CMAKE_SOURCE_DIR}/algorithm)

add_executable (heapTest heapTest.cpp)

add_dependencies(heapTest Algorithm)

target_link_libraries(heapTest ${LibsAlgo})
target_include_directories (heapTest PRIVATE ${IncludesTest})

INSTALL(FILES ${Test_BINARY_DIR}/heapTest DESTINATION bin)
