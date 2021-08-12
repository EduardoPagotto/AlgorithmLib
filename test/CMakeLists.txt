cmake_minimum_required(VERSION 3.18.4)

PROJECT(Test)

#define os Lib's a serem usados
set (LibsAlgo ${CMAKE_SOURCE_DIR}/bin/libAlgorithm.a
			  -lpthread)

#define os includes
set (IncludesTest ${CMAKE_SOURCE_DIR}/algorithm)

add_executable (heapTest heapTest.cpp)
add_executable (bitMapTest bitMapTest.cpp)

add_dependencies(heapTest Algorithm)
add_dependencies(bitMapTest Algorithm)

target_link_libraries(heapTest ${LibsAlgo})
target_link_libraries(bitMapTest ${LibsAlgo})

target_include_directories (heapTest PRIVATE ${IncludesTest})
target_include_directories (bitMapTest PRIVATE ${IncludesTest})

INSTALL(FILES ${Test_BINARY_DIR}/heapTest DESTINATION bin)
INSTALL(FILES ${Test_BINARY_DIR}/bitMapTest DESTINATION bin)
