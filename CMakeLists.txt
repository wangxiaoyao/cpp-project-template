##cmake最低版本要求
cmake_minimum_required(VERSION 3.16.5)

##项目名称
project(HelloWorld)

##头文件
include_directories(include)

##链接写好的静态库
link_directories(${PROJECT_SOURCE_DIR}/lib)
link_libraries(Operate)

##主cmakelist中添加子目录,这里是用于静态库
add_subdirectory(lib)

##包含的项目源文件,存放在变量SRC_LIST里面
aux_source_directory(src SRC_LIST)


##执行生成的项目名为helloworld  目标源码在上面设的变量里
add_executable(${PROJECT_NAME} ${SRC_LIST})

## 设置最终可执行文件放在bin里面,由于定义好的不需要${}
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin ) 

## 开启
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -glldb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")


## 链接静态库(注意必须放在末尾处)
target_link_libraries(${PROJECT_NAME} hello)