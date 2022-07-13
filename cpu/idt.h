#ifndef IDT_H
#define IDT_H

#include "types.h"

// segment selectors
#define KERNEL_CS 0x08

// how every interrupt gate (handler) is defined
typedef struct {
    u16 low_offset; // lower 16 bits of handler function address
    u16 selector; // kernel segment selector
    u8 always_zero;
    u8 flags; 
    u16 high_offset; // higher 16 bits of handler function address
} __attribute__((packed)) idt_gate_t;

typedef struct {
    u16 limit;
    u32 base;
} __attribute__((packed)) idt_register_t;

#define IDT_ENTRIES 256

// functions implemented in idt.c
void set_idt_gate(int n, u32 handler);
void set_idt();

#endif