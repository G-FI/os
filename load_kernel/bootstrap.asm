;bootsector
;***********************;
[org 0x7c00]
KERNEL_OFFSET equ 0x1000

mov [BOOT_DIRVE], dl

mov bp, 0x9000
mov sp, bp

mov bx, MSG_REAL_MODE
call print
call print_ln

call load_kernel

call switch_to_pm

jmp $

%include"../boot_sector/boot_sect_print.asm"
%include"../boot_sector/boot_sect_disk.asm"
%include"../32bit_protect_mode/32bit_print.asm"
%include"../32bit_protect_mode/32bit_gdt.asm"
%include"../32bit_protect_mode/32bit_switch.asm"
[bits 16]
;load kernel
load_kernel:
    mov bx, MSG_LOAD_KERNEL
    call print
    call print_ln

    mov bx, KERNEL_OFFSET ;kernel 被加载到内存位置
    mov dh, 2            ;加载1个扇区
    mov dl, [BOOT_DIRVE]
    call disk_load

    ret

;after switch to protect mode
[bits 32]
BEGIN_PM:
    mov ebx, MSG_PROT_MODE
    call print_string_pm

    call KERNEL_OFFSET ;进入kernel code 

jmp $

BOOT_DIRVE db 0
MSG_REAL_MODE db 'Start in 16-bit real mode', 0
MSG_PROT_MODE db 'Successfully landed in 32-bit portect mode', 0
MSG_LOAD_KERNEL db 'Loading kernel into memory', 0

times 510-($-$$) db 0
dw 0xaa55
;**********************;
