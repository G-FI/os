;arg: bx->string address
print_string:
    pusha
start:  
    mov al, [bx]
    cmp al, 0
    je done
    mov ah, 0x0e
    int 0x10
    inc bx
    jmp start

done:
    popa
    ret

print_ln:
    pusha

    mov ah, 0x0e
    mov al, 0x0a
    int 0x10
    mov ah, 0x0e
    mov al, 0x0d
    int 0x10
    
    popa
    ret
