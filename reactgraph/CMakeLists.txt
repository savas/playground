cmake_minimum_required(VERSION 3.2)
project(reactgraph)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_INCLUDE_DIR /Users/savasp/dev/ext/boost/include)
include_directories(${Boost_INCLUDE_DIR} /usr/local/include)
link_directories(${Boost_LIBRARY_DIR} /usr/local/lib)
find_package(Boost COMPONENTS system filesystem REQUIRED)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

#set(CXX "/usr/local/Cellar/gcc/5.1.0/bin/g++-5")
#set(CMAKE_CXX_COMPILER ${CXX})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/main.cpp)

add_subdirectory(src/graph)

add_executable(testgraph ${SOURCE_FILES})
target_link_libraries(testgraph ${Boost_LIBRARIES} network-uri reactgraph)