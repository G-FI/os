;arg: dx, dh-> number of secotr to read, dl->drive number
;load dh number of sector to es:bx from drive dl
disk_load:
    pusha 

    push dx ; used to error check

    mov ah, 0x02 ;function read
    mov al, dh ;number of sector to read
 
    mov ch, 0x00 ; cylinder number
    mov dh, 0x00 ;head number
    mov cl, 0x02 ;sector index; [1..17], 2 is frist sector after boot_sector


    int 0x13 ; disk interrupt
    jc disk_error ;carry flag will be set if error
    
    pop dx
    cmp dh, al
    jne disk_error
    popa
    ret

disk_error:
    mov bx, DISK_ERROR_MSG
    call print_string
    jmp $

DISK_ERROR_MSG db 'Disk read error!', 0


