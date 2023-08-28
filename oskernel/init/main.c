//
// Created by ziya on 22-6-23.
//

#include "../include/linux/tty.h"
#include "../include/linux/kernel.h"

/**
 * 实现可变参数的本质就是获取参数
 * 需要你熟悉执行流及调用约定
 *
 * ebp                  <-----ebp
 * return address
 * 3                    0x00                03 00 00 00
 * 0x11                 0x04                11 00 00 00
 * 0xaa                 0x08                aa 00 00 00
 * 0x11223344           0x0c                44 33 22 11
 * --------------------
 * @param arg_cnt
 * @param ...
 */
void test(int arg_cnt, ...) {
    /**
     * 实现可变参数需要:
     * 1 找到最后一个参数
     * -------------------
     * 2 取出参数
     * 3 移动指针
     * -------------------
     * 这两步需要同时完成
     */

//    char* p = &arg_cnt;
//    p += arg_cnt;

    char* p = (char*)&arg_cnt + sizeof(char*);

    int v;

    // 这样写, 就没办法实现可变参数
//    v = *(int*)p;
//    v = *(int*)(p + sizeof(char*));
//    v = *(int*)(p + sizeof(char*) + sizeof(char*));

    // 这样写, 做了两件事情:1 修改p指针; 2 移动到要取的参数的位置
    v = *(int*)((p += sizeof(char*)) - sizeof(char*));
//    v = *(int*)((p += sizeof(char*)) - sizeof(char*));
//    v = *(int*)((p += sizeof(char*)) - sizeof(char*));
}

void kernel_main(void) {
    console_init();

    test(3, 0x11, 0xaa, 0x11223344);

    while (true);
}