#ifndef IDT_H
#define IDT_H

#include <stdint.h>

// IDT Entry Structure
struct idt_entry {
    uint16_t base_low;
    uint16_t sel;
    uint8_t always0;
    uint8_t flags;
    uint16_t base_high;
} __attribute__((packed));

// IDT Pointer Structure
struct idt_ptr {
    uint16_t limit;
    uintptr_t base;  // Waxaa bedelnay uint32_t -> uintptr_t si 32-bit iyo 64-bit u shaqeeyaan
} __attribute__((packed));

// Functions
void init_idt();
void set_idt_entry(int num, uint32_t base, uint16_t sel, uint8_t flags);

#endif
