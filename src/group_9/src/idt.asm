global idt_load
section .text

idt_load:
    lidt [rdi]  ; Load IDT pointer (64-bit)
    ret
