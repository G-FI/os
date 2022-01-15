[org 0x7c00]

mov bp, 0x8000
mov sp, bp

mov ax, 0x00
push ax ; sp = 0x7ffe

push ax ; sp = 0x7ffc

mov dx, sp
call print_hex
call print_ln

sub sp, 0x04
mov dx, sp
call print_hex
call print_ln

jmp $
%include"boot_sect_print_hex.asm"
%include"boot_sect_print.asm"


times 510 - ($-$$) db 0

dw 0xaa55

