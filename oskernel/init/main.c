//
// Created by ziya on 22-6-23.
//

#include "../include/linux/tty.h"
#include "../include/linux/kernel.h"
#include "../include/linux/traps.h"

void kernel_main(void) {
    console_init();
    gdt_init();
    idt_init();

    printk("ziya os cool\n");

    __asm__("sti;");

    int i = 10 / 0;

    while (true);
}