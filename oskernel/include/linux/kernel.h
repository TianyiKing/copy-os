//
// Created by ziya on 22-6-26.
//

#ifndef ZIYA_OSKERNEL_TEACH_KERNEL_H
#define ZIYA_OSKERNEL_TEACH_KERNEL_H

#include "../stdarg.h"

int vsprintf(char *buf, const char *fmt, va_list args);

int printk(const char * fmt, ...);

#endif //ZIYA_OSKERNEL_TEACH_KERNEL_H
