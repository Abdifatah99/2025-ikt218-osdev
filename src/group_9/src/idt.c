#include "idt.h"
#include <string.h>
#include <stdint.h>  // Waxaa lagu daray si `uintptr_t` loo isticmaalo

#define IDT_SIZE 256
#define KERNEL_CODE_SEGMENT 0x08

// IDT table iyo pointer-keeda
struct idt_entry idt[IDT_SIZE];
struct idt_ptr idtp;

// Function lagu dhisayo IDT Entry
void set_idt_entry(int num, uint32_t base, uint16_t sel, uint8_t flags) {
    idt[num].base_low = base & 0xFFFF;
    idt[num].sel = sel;
    idt[num].always0 = 0;
    idt[num].flags = flags | 0x60;  // Waxaan hubineynaa in flags si sax ah loo xisaabiyo
    idt[num].base_high = (base >> 16) & 0xFFFF;
}

// Assembly function lagu shubanayo IDT
extern void idt_load(struct idt_ptr*);

// Function lagu initializing IDT
void init_idt() {
    idtp.limit = (sizeof(struct idt_entry) * IDT_SIZE) - 1;
    idtp.base = (uintptr_t)&idt;  // Waxaa la bedelay uint32_t -> uintptr_t

    memset(&idt, 0, sizeof(struct idt_entry) * IDT_SIZE);

    idt_load(&idtp);  // Load IDT via assembly
}
