[SECTION .text]
[BITS 32]
extern kernel_main

global _start

_start:
    ; 修改栈顶
    mov esp, 0x9fbff

    mov byte [0xb8002], 'Z';

    ; 尝试访问1M以上的内存   0x100000
    mov byte [0x200000], 0x11

    call kernel_main

    xchg bx, bx
    jmp $