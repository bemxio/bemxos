disk_load:
    pusha
    push dx

    mov ah, 0x02 ; an 'int 0x13' function for reading stuff
    mov al, dh ; number of sectors to read

    mov cl, 0x02 ; sector (0x02 is the first 'available' sector)
    mov ch, 0x00 ; cylinder (from 0x0 to 0x3FF)
    mov dh, 0x00 ; head number (from 0x0 to 0xF)

    int 0x13 ; BIOS interrupt
    jc disk_error ; if something bad happened

    pop dx
    cmp al, dh
    jne sector_error ; if al (number of sectors that got read) is not equal to dh (number of sectors to read)

    popa
    ret

disk_error:
    mov bx, DISK_ERROR
    call println

    mov dh, ah ; ah is the error code, dl is the disk drive that raised the error
    call print_hex

    hlt

sector_error:
    mov bx, SECTOR_ERROR
    call print

DISK_ERROR: db "Disk read error", 0
SECTOR_ERROR: db "Incorrect number of sectors read", 0