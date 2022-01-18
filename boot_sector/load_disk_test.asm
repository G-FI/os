[org 0x7c00]
    mov [DRIVE_NUMBER], dl ; store for latter use
    ;set stack 
    mov bp, 0x8000
    mov sp, bp

    ;load address es:bx
    mov bx, 0x9000

    ;number of sectors
    mov dh, 2
    ;driver number
    mov dl, [DRIVE_NUMBER]

    call disk_load

    mov dx, [0x9000]
    call print_hex
    call print_ln

    mov dx, [0x9000 + 512]
    call print_hex
    call print_ln

jmp $

DRIVE_NUMBER:
    db 0

%include"boot_sect_disk.asm"
%include"boot_sect_print.asm"
%include"boot_sect_print_hex.asm"

times 510 - ($-$$) db 0

dw 0xaa55

times 256 dw 0xdada
times 256 dw 0xface


