global isr0, isr1, isr2

isr0:
    cli
    push 0
    push 0
    call isr_handler
    add esp, 8
    sti
    iret

isr1:
    cli
    push 0
    push 1
    call isr_handler
    add esp, 8
    sti
    iret

isr2:
    cli
    push 0
    push 2
    call isr_handler
    add esp, 8
    sti
    iret
