//
// Created by ziya on 22-7-6.
//

#ifndef ZIYA_OSKERNEL_RESEARCH_TASK_H
#define ZIYA_OSKERNEL_RESEARCH_TASK_H

#include "types.h"
#include "mm.h"

// 进程上限
#define NR_TASKS 64

typedef void* (*task_fun_t)(void*);

typedef struct task_t {
    int             pid;
    int             cr3;
}task_t;

typedef union task_union_t {
    task_t task;
    char stack[PAGE_SIZE];
}task_union_t;

task_t* create_task(char* name, task_fun_t fun);

void task_init();

#endif //ZIYA_OSKERNEL_RESEARCH_TASK_H
