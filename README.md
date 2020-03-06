# cpp-project-template

关于c/cpp的项目工程。包括cmake以及makefile的使用。


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
## 给项目工程添加： 头文件目录
include_directories(目录A  目录B)

## 向当前工程添加存放源文件的子目录，并可以指定中间二进制和目标二进制的存放位置
add_subdirectory()

## 把指定目录下所有的源文件 存储在一个变量中，
aux_source_directory(src  SRC_LIST)

## 手动可以使用set
set( SRC_LIST
	 ./main.c
	 ./testFunc1.c
	 ./testFunc.c)

## 目标生成文件 和 源文件
add_executable(main main.c)

## 预设的两个变量
- EXECUTABLE_OUTPUT_PATH ：目标二进制可执行文件的存放位置。没有花括号
- PROJECT_SOURCE_DIR：工程的根目录
set (  EXECUTABLE_OUTPUT_PATH   ${PROJECT_SOURCE_DIR}/bin ) 

```