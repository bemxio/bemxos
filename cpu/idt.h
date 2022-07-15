#ifndef IDT_H
#define IDT_H

#include <stdint.h>

// segment selectors
#define KERNEL_CS 0x08

// how every interrupt gate (handler) is defined
typedef struct {
    uint16_t low_offset; // lower 16 bits of handler function address
    uint16_t selector; // kernel segment selector
    uint8_t always_zero;
    uint8_t flags; 
    uint16_t high_offset; // higher 16 bits of handler function address
} __attribute__((packed)) idt_gate_t;

typedef struct {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed)) idt_register_t;

#define IDT_ENTRIES 256

// functions implemented in idt.c
void set_idt_gate(int n, uint32_t handler);
void set_idt();

#endif