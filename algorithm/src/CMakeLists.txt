cmake_minimum_required(VERSION 3.18.4)

PROJECT(Algorithm)

#define objetos a compilar
set (AlgorithmSource HeapQ.cpp Heap.cpp)

#define os includes
set (AlgorithmInclude ${CMAKE_SOURCE_DIR}/algorithm) # Raiz do projeto

# Define o Target
add_library (Algorithm STATIC ${AlgorithmSource})

# Define os includes privados para este target
target_include_directories (Algorithm PUBLIC ${AlgorithmInclude})

INSTALL(FILES ${Algorithm_BINARY_DIR}/libAlgorithm.a DESTINATION lib)
INSTALL(DIRECTORY ${AlgorithmInclude}/algorithm DESTINATION ${CMAKE_INSTALL_PREFIX}/include/algorithm FILES_MATCHING PATTERN "*.h*")
