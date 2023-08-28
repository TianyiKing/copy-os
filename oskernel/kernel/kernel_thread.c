//
// Created by ziya on 23-1-15.
//
#include "../include/linux/kernel.h"
#include "../include/linux/hd.h"
#include "../include/linux/fs.h"
#include "../include/linux/task.h"
#include "../include/ya_shell.h"

extern task_t* current;

task_t* wait_for_request = NULL;

void kernel_thread_fun(void* arg) {
    hd_init();

    char str[512] = "ziya";
    bwrite(1, 0, str, 512);

    buffer_head_t* buff1 = bread(1, 0, 1);
    printk("%s\n", buff1->data);

    active_ya_shell();

    while (true);
}