cmake_minimum_required(VERSION 3.2)
project(reactgraph)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_INCLUDE_DIR /Users/savasp/dev/ext/boost/include)
set(Boost_LIBRARY_DIR /Users/savasp/dev/ext/boost/lib)
include_directories(${Boost_INCLUDE_DIR} /usr/local/include)
link_directories(${Boost_LIBRARY_DIR} /usr/local/lib)
find_package(Boost COMPONENTS system filesystem REQUIRED)

#set(CXX "/usr/local/Cellar/gcc/5.1.0/bin/g++-5")
#set(CMAKE_CXX_COMPILER ${CXX})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    in-memory/InMemoryReactiveEdge.cpp
    in-memory/InMemoryReactiveEdge.h
    in-memory/InMemoryReactiveNode.cpp
    in-memory/InMemoryReactiveNode.h
    in-memory/Utilities.h
    EdgeIf.h
    Identity.h
    NodeIf.h
    ReactiveEdgeIf.h
    ReactiveNodeIf.h
    Value.h)

add_library(reactgraph ${SOURCE_FILES})
target_link_libraries(reactgraph ${Boost_LIBRARIES} network-uri)