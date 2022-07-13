[org 0x7c00] ; bootloader offset
KERNEL_OFFSET equ 0x1000 ; the same one used when linking the kernel

mov bp, 0x9000 ; set the stack
mov sp, bp

mov bx, MSG_REAL_MODE
call println ; this will be written after the BIOS messages

call load_kernel ; read the kernel from  the disk
call switch_to_pm ; disable interrupts, load GDT, etc.
jmp $ ; this will actually never be executed

; printing functions
%include "boot/functions/print.asm"
%include "boot/functions/print32.asm"
%include "boot/functions/print_hex.asm"

; other needed functions for loading the kernel
%include "boot/functions/disk.asm"
%include "boot/functions/gdt.asm"
%include "boot/functions/switch_pm.asm"

[bits 16]
load_kernel:
    mov bx, MSG_LOAD_KERNEL
    call println

    mov bx, KERNEL_OFFSET ; read from disk and store in 0x1000
    mov dh, 32 ; number of sectors to read (make sure to expand it when the kernel code gets big)
    mov dl, [BOOT_DRIVE]

    call disk_load
    ret

[bits 32]
BEGIN_PM: ; after the switch we will get here
    mov ebx, MSG_PROT_MODE
    call print32 ; note that this will be written at the top left corner
    
    call KERNEL_OFFSET ; give control to the kernel
    jmp $ ; stay here when the kernel returns control to us (if ever)

; constants
MSG_REAL_MODE db "Started in 16-bit real mode", 0
MSG_PROT_MODE db "Loaded 32-bit protected mode", 0
MSG_LOAD_KERNEL db "Loading kernel into memory...", 0

BOOT_DRIVE db 0

; padding & magic number
times 510-($-$$) db 0
dw 0xaa55