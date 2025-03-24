global irq0, irq1

irq0:
    cli
    push 0
    push 32
    call irq_handler
    add esp, 8
    sti
    iret

irq1:
    cli
    push 0
    push 33
    call irq_handler
    add esp, 8
    sti
    iret
