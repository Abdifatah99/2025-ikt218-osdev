#include "keyboard.h"
#include "irq.h"
#include <stdio.h>

#define KEYBOARD_PORT 0x60

char scancode_to_ascii[] = {
        0,  27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',
        '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',
        0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`',
        0, '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0,
        '*', 0, ' '
};

void keyboard_handler() {
    uint8_t scancode = inb(KEYBOARD_PORT);
    if (scancode < sizeof(scancode_to_ascii)) {
        printf("%c", scancode_to_ascii[scancode]);
    }
}

void keyboard_install() {
    set_idt_entry(33, (uint32_t)keyboard_handler, 0x08, 0x8E);
}
