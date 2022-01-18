[bits 32]
VIDEO_MEMORY equ 0xb8000
WHITE_ON_BLCK equ 0x0f

; arg: ebx--> the string's address
print_string_pm:
    pusha
    mov edx, VIDEO_MEMORY; edx 用来索引video_memory

print_string_pm_loop:
    mov ah, WHITE_ON_BLCK
    mov al, [ebx]

    cmp al, 0
    je print_string_pm_done

    mov [edx], ax
    add edx, 2 ;显示一个字符需要向video memory 复制了两个字节ax
    add ebx, 1 
    jmp print_string_pm_loop

print_string_pm_done:
    popa
    ret