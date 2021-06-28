cmake_minimum_required(VERSION 3.19)
project(Client)

set(CMAKE_CXX_STANDARD 14)
set(BOOST_ROOT /usr/include/boost)
set(Boost_USE_STATIC_LIBS ON)

find_package(Boost COMPONENTS asio)
find_package(Threads)

include_directories(${Boost_INCLUDE_DIR})

add_executable(Client Client.cpp)
target_link_libraries(Client Boost::boost Threads::Threads)