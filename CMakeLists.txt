#build 目录执行  cmake .. && make
cmake_minimum_required(VERSION 2.8)
PROJECT(my_rectangle) 
set(CMAKE_CXX_STANDARD 11)  # 将 C++ 标准设置为 C++ 11
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # C++ 11 是强制要求，不会衰退至低版本
SET(CMAKE_BUILD_TYPE "Debug") #Debug模式
#SET(CMAKE_BUILD_TYPE "Release") #Release模式
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall  -fno-inline -g")  #Debug模式下添加的编译选项
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")  #Release模式下添加的编译选项
FILE(GLOB SOURCE_SRC "${CMAKE_SOURCE_DIR}/src/*.cpp")  #普通源文件
FILE(GLOB SOURCE_MAIN "${CMAKE_SOURCE_DIR}/main.cpp") #主程序文件
#FILE(GLOB SOURCE_LIBSRC_HELLO2 "${CMAKE_SOURCE_DIR}/libsrc_hello2/*.cpp") #hello2库的源文件
INCLUDE_DIRECTORIES("${CMAKE_SOURCE_DIR}/include/")  #头文件
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)  #动态库（.so）生成目录


#add_library(hello2 SHARED ${SOURCE_LIBSRC_HELLO2}) #添加hello2动态库
#link_libraries(hello2) #链接生成
ADD_EXECUTABLE(${PROJECT_NAME} ${SOURCE_SRC} ${SOURCE_MAIN}) #生成可执行文件 可执行文件名
#target_link_libraries(${PROJECT_NAME} ${hello2})  #链接动态库

#加载Boost
find_package(Boost COMPONENTS json)

include_directories(${Boost_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})