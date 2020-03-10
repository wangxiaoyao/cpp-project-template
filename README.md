# cpp-project-template

关于c/cpp的项目工程。包括cmake以及makefile的使用。

## 相关名词

1 configure： 这个文件是用来检测本程序需要到函数库，编译器和其他资料。检测程序的文件名：configure。  ./configure 来生成Makefile

2 Makefile： make依据makefile文件来编译文件

3 CMake： 手动书写不同平台的Makefile太麻烦。 利用CMake进行跨平台。cmake通过读取 CMakeLists.txt 脚本进行构建。如同make需要makefile。 优势：

- 1  跨平台：
CMake是开源、跨平台的构建工具，可以让我们通过编写简单的配置文件去生成本地的Makefile，这个配置文件是独立于运行平台和编译器的，这样就不用亲自去编写Makefile了，而且配置文件可以直接拿到其它平台上使用，

- 2 支持多个IDE
VS, QtCreator, Eclipse, CLion  。CMake 是除了各官方（苹果，谷歌）构建系统之外的推荐构建系统。


## 项目树

```
├── CMakeLists.txt   ： Cmake规则文件
├── LICENSE  ： 许可文件
├── README.md ： 项目说明文件
├── bin ： 二进制文件
├── tools ：有用的sh脚本工具, 比如清除所有cmake生成的文件
├── include ： 头文件
├── lib ： 库文件
└── src ： 源码
```

## Cmake相关说明

变量写法： ${var}

```
##cmake最低版本要求
cmake_minimum_required(VERSION 3.16.5)

##项目名称
project(HelloWorld)

## 给项目工程添加： 头文件目录
include_directories(目录A  目录B)

## 静态库目录
link_directories(lib)

## 静态库名称 去掉lib 和 .a
link_libraries(Operate)

## 添加源文件子目录。那么回去找子目录中的CMakeLists
add_subdirectory(目录A 目录B)

## 子目录CMakeLists 添加
ADD_LIBRARY(hello STATIC ${LIBHELLO_SRC})

## 子目录生成动态库或者静态库
ADD_LIBRARY(hello SHARED/STATIC ${LIBHELLO_SRC})

## 把指定目录下所有的源文件 存储在一个变量中，
aux_source_directory(src  SRC_LIST)

## 手动可以使用set
set( SRC_LIST
	 ./main.c
	 ./testFunc1.c
	 ./testFunc.c)

## 目标生成文件 和 源文件
add_executable(main main.c)

## 预设的变量
- EXECUTABLE_OUTPUT_PATH ：可执行文件目录
- LIBRARY_OUTPUT_PATH :  共享库目录
- PROJECT_SOURCE_DIR：工程的根目录
set (  EXECUTABLE_OUTPUT_PATH   ${PROJECT_SOURCE_DIR}/bin ) 

## 链接静态库(注意必须放在末尾处)
target_link_libraries(${PROJECT_NAME} hello)
```


## gdb调试

debug 版和 release 版的程序。debug 版的项目生成的可执行文件需要有调试信息并且不需要进行优化,而 release 版的不需要调试信息但需要优化。这是由gcc的参数决定的，见下-O0不优化。-O3最高优化

```
## cmake中开启

-ggdb 或者 -glldb

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

## 终端使用
cmake -DCMAKE_BUILD_TYPE=Debug CMakeLists.txt
cmake -DCMAKE_BUILD_TYPE=Release CMakeLists.txt
```



