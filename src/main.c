#include <stdio.h>
#include "addFun.h"
#include "lib_operate.h"
#include "hello.h"


int main(){
    HelloFunc();
    printf("外接函数值为：%d\n",addFun(2,3));
    printf("外接静态库函数为：%d\n",libSub(3,2));
    printf("hello world");
}
