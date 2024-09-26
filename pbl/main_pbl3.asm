section .data
    msg1 db "Base Address: ",10
    msgl1 equ $-msg1
    
    msg2 db "Offset: ",10
    msgl2 equ $-msg2
    
    msg3 db "Global descriptor table register",10
    msgl3 equ $-msg3
    
    msg4 db "Interrupt descriptor table register",10
    msgl4 equ $-msg4
    
    msg5 db "Local descriptor table register",10
    msgl5 equ $-msg5
    
    msg6 db "Task Register",10
    msgl6 equ $-msg6
    
    msg7 db "Machine status word",10
    msgl7 equ $-msg7
    
    newl db 10

    %macro operate 4
        mov rax,%1
        mov rdi,%2
        mov rsi,%3
        mov rdx,%4
        syscall
    %endmacro


section .bss
    
    gdtr resq 1
    gdtlimit resw 1
    
    idtr resq 1
    idtlimit resw 1
    
    ldtr resw 1
    tr resw 1
    msw resw 1
    res64 resb 16
    res16 resb 4
    temp resb 1
    
    
section .text
    global _start
    _start:
    
        operate 1,1,msg3,msgl3
        operate 1,1,msg1,msgl1
        mov esi,gdtr
        sgdt [esi]
        mov rax,[esi]
        call display64
        
        operate 1,1,newl,1
        operate 1,1,msg2,msgl2
        mov esi,gdtlimit
        mov ax,[esi]
        call display16
        
        operate 1,1,newl,1
        operate 1,1,msg4,msgl4
        operate 1,1,newl,1
        operate 1,1,msg1,msgl1
        mov esi,idtr
        sidt [esi]
        mov rax,[esi]
        call display64
        
        operate 1,1,newl,1
        operate 1,1,msg2,msgl2
        mov esi,idtlimit
        mov ax,[esi]
        call display16
        
        operate 1,1,newl,1
        operate 1,1,msg5,msgl5
        operate 1,1,newl,1
        operate 1,1,msg1,msgl1
        mov esi,ldtr
        sldt [esi]
        mov ax,[esi]
        call display16
        
        operate 1,1,newl,1
        operate 1,1,msg6,msgl6
        operate 1,1,newl,1
        operate 1,1,msg1,msgl1
        mov esi,tr
        str [esi]
        mov ax,[esi]
        call display16
        
        operate 1,1,newl,1
        operate 1,1,msg7,msgl7
        operate 1,1,newl,1
        operate 1,1,msg1,msgl1
        mov esi,msw
        smsw [esi]
        mov ax,[esi]
        call display16
        
        
        operate 60,0,0,0
        
        display64:
            
            mov bp,16
            
            again:
                rol rax,4
                mov [res64],rax
                and rax,0FH
                cmp rax,09H
                jbe down
                add rax,07H
                
                down:
                    add rax,30H
                    mov byte[temp],al
                    operate 1,1,temp,1
                    mov rax,[res64]
                    dec bp
                    jnz again
            ret
            
        display16:
        
            mov bp,4
            
            again2:
                rol ax,4
                mov [res16],ax
                and ax,0FH
                cmp ax,09H
                jbe down2
                add ax,07H
                
                down2:
                    add ax,30H
                    mov byte[temp],al
                    operate 1,1,temp,1
                    mov rax,[res16]
                    dec bp
                    jnz again2
            retsection .data
    msg1 db "Base Address: ",10
    msgl1 equ $-msg1
    
    msg2 db "Offset: ",10
    msgl2 equ $-msg2
    
    msg3 db "Global descriptor table register",10
    msgl3 equ $-msg3
    
    msg4 db "Interrupt descriptor table register",10
    msgl4 equ $-msg4
    
    msg5 db "Local descriptor table register",10
    msgl5 equ $-msg5
    
    msg6 db "Task Register",10
    msgl6 equ $-msg6
    
    msg7 db "Machine status word",10
    msgl7 equ $-msg7
    
    newl db 10

    %macro operate 4
        mov rax,%1
        mov rdi,%2
        mov rsi,%3
        mov rdx,%4
        syscall
    %endmacro


section .bss
    
    gdtr resq 1
    gdtlimit resw 1
    
    idtr resq 1
    idtlimit resw 1
    
    ldtr resw 1
    tr resw 1
    msw resw 1
    res64 resb 16
    res16 resb 4
    temp resb 1
    
    
section .text
    global _start
    _start:
    
        operate 1,1,msg3,msgl3
        operate 1,1,msg1,msgl1
        mov esi,gdtr
        sgdt [esi]
        mov rax,[esi]
        call display64
        
        operate 1,1,newl,1
        operate 1,1,msg2,msgl2
        mov esi,gdtlimit
        mov ax,[esi]
        call display16
        
        operate 1,1,newl,1
        operate 1,1,msg4,msgl4
        operate 1,1,newl,1
        operate 1,1,msg1,msgl1
        mov esi,idtr
        sidt [esi]
        mov rax,[esi]
        call display64
        
        operate 1,1,newl,1
        operate 1,1,msg2,msgl2
        mov esi,idtlimit
        mov ax,[esi]
        call display16
        
        operate 1,1,newl,1
        operate 1,1,msg5,msgl5
        operate 1,1,newl,1
        operate 1,1,msg1,msgl1
        mov esi,ldtr
        sldt [esi]
        mov ax,[esi]
        call display16
        
        operate 1,1,newl,1
        operate 1,1,msg6,msgl6
        operate 1,1,newl,1
        operate 1,1,msg1,msgl1
        mov esi,tr
        str [esi]
        mov ax,[esi]
        call display16
        
        operate 1,1,newl,1
        operate 1,1,msg7,msgl7
        operate 1,1,newl,1
        operate 1,1,msg1,msgl1
        mov esi,msw
        smsw [esi]
        mov ax,[esi]
        call display16
        
        
        operate 60,0,0,0
        
        display64:
            
            mov bp,16
            
            again:
                rol rax,4
                mov [res64],rax
                and rax,0FH
                cmp rax,09H
                jbe down
                add rax,07H
                
                down:
                    add rax,30H
                    mov byte[temp],al
                    operate 1,1,temp,1
                    mov rax,[res64]
                    dec bp
                    jnz again
            ret
            
        display16:
        
            mov bp,4
            
            again2:
                rol ax,4
                mov [res16],ax
                and ax,0FH
                cmp ax,09H
                jbe down2
                add ax,07H
                
                down2:
                    add ax,30H
                    mov byte[temp],al
                    operate 1,1,temp,1
                    mov rax,[res16]
                    dec bp
                    jnz again2
            ret