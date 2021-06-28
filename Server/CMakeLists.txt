cmake_minimum_required(VERSION 3.19)
project(ProjectServer)

set(CMAKE_CXX_STANDARD 14)
set(BOOST_ROOT /usr/include/boost)
set(Boost_USE_STATIC_LIBS ON)

find_package(Boost COMPONENTS asio)
find_package(Threads)

include_directories(${Boost_INCLUDE_DIR})

add_executable(ProjectServer main.cpp Server.cpp Server.h Connection.cpp Connection.h)
target_link_libraries(ProjectServer Boost::boost Threads::Threads)