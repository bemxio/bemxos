#include "idt.h"

#define low_16(address) (uint16_t)((address) & 0xFFFF)
#define high_16(address) (uint16_t)(((address) >> 16) & 0xFFFF)

idt_gate_t idt[IDT_ENTRIES];
idt_register_t idt_register;

void set_idt_gate(int n, uint32_t handler) {
    idt[n].low_offset = low_16(handler);
    idt[n].selector = KERNEL_CS;
    idt[n].always_zero = 0;
    idt[n].flags = 0x8E;
    idt[n].high_offset = high_16(handler);
}

void set_idt() {
    idt_register.base = (uint32_t) &idt;
    idt_register.limit = IDT_ENTRIES * sizeof(idt_gate_t) - 1;

    // don't make the mistake of loading &idt, always load &idt_register
    __asm__ __volatile__("lidtl (%0)" : : "r" (&idt_register));
}