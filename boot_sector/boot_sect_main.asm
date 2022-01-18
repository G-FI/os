[org 0x7c00]

mov dx, [HELLO]
call print_hex

jmp $


%include"boot_sect_print.asm"
%include"boot_sect_print_hex.asm"
HELLO:
    db '0000',0



times 510-($-$$) db 0

dw 0xaa55