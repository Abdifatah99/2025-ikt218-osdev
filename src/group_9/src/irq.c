#include "irq.h"
#include "idt.h"
#include <stdio.h>

// Declare IRQ handlers
extern void irq0();
extern void irq1();

void irq_install() {
    set_idt_entry(32, (uint32_t)irq0, 0x08, 0x8E);
    set_idt_entry(33, (uint32_t)irq1, 0x08, 0x8E);
}

// IRQ Handler function
void irq_handler(int irq) {
    printf("IRQ %d received!\n", irq);
}
