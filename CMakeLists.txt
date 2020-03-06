##cmake最低版本要求
cmake_minimum_required(VERSION 3.16.5)

##项目名称
project(HelloWorld)

##头文件
include_directories(include)

##包含的项目源文件,存放在变量SRC_LIST里面
aux_source_directory(src SRC_LIST)


##执行生成的项目名为helloworld  目标源码在上面设的变量里
add_executable(${PROJECT_NAME} ${SRC_LIST})

## 设置最终可执行文件放在bin里面,由于定义好的不需要${}
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin ) 
