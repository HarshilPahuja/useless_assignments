%macro scall 4
		mov rax, %1
		mov rdi, %2
		mov rsi, %3
		mov rdx, %4
		syscall
%endmacro

section .data
		m1 db 10, "Enter the first string: "
		l1 equ $-m1
		m2 db 10, "Enter the second string: "
		l2 equ $-m2
		m3 db 10, "The concatenated string is: "
		l3 equ $-m3		
		m4 db 10, "No of words: "
		l4 equ $-m4		
		m5 db 10, "No of spaces: "
		l5 equ $-m5
				
section .bss 		
		string1 resb 25
		string2 resb 25
		string3 resb 50
		words resb 1
		spaces resb 1
		length1 resb 25
		length12 resb 25
		length2 resb 25
				
section .text
global _start
_start:
		scall 1,1,m1,l1
		scall 0,0,string1,25
		dec rax
		mov [length1], rax
		mov [length12], rax
		scall 1,1,m2,l2
		scall 0,0,string2,25
		dec rax
		mov [length2], rax
		call Concatenate
		call word_space
		scall 60,0,0,0
Concatenate: 
		mov rsi, string1
		mov rdi, string3
copy1: 
		mov AL, [rsi]
		mov [rdi], AL
		inc rsi
		inc rdi
		dec byte[length1]
		jnz copy1
		mov rsi, string2
copy2:
		mov AL, [rsi]
		mov [rdi], AL
		inc rsi
		inc rdi
		dec byte[length2]
		jnz copy2
		scall 1,1,m3,l3
		scall 1,1,string3,50
		RET
word_space: 
		mov rsi, string1
		mov BL, 00
up: 
		mov AL, [rsi]
		cmp AL, 20H
		jne nspace
		inc bl
nspace: 
		inc rsi
		dec byte[length12]
		jnz up
		scall 1,1,m5, l5
		add BL, 30H
		mov [spaces], BL
		scall 1,1,spaces,1
		scall 1,1,m4,l4
		inc BL
		mov [words], BL
		scall 1,1,words,1
		RET
