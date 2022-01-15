[bits 16]; include会将文件复制进去
switch_to_pm:
cli            ;clear interrupt
lgdt [gdt_descriptor]

mov eax, cr0
or eax, 0x1
mov cr0, eax

jmp CODE_SEG:init_pm ;jmp automatically set cs to corresponding segment
;This also forces the CPU to flush its cache of
; pre - fetched and real - mode decoded instructions , which can
; cause problems.



[bits 32]
init_pm:
;update segment registers
mov ax, DATA_SEG
mov ds, ax
mov ss, ax
mov es, ax
mov fs, ax
mov gs, ax
;update stack position
mov ebp, 0x90000
mov esp, ebp

call BEGIN_PM
