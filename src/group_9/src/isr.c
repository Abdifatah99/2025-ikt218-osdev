#include "isr.h"
#include "idt.h"
#include <stdio.h>

// Declare ISR handlers
extern void isr0();
extern void isr1();
extern void isr2();
// Function to install ISRs
void isr_install() {
    set_idt_entry(0, (uint32_t)isr0, 0x08, 0x8E);
    set_idt_entry(1, (uint32_t)isr1, 0x08, 0x8E);
    set_idt_entry(2, (uint32_t)isr2, 0x08, 0x8E);
}

// ISR handler
void isr_handler() {
    printf("Interrupt received!\n");
}
