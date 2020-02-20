data segment
	string1 db "a string for testing",0ah,0dh,'$'
	string2 db "found",0ah,0dh,'$'
	string3 db "not found",0ah,0dh,'$'
	string4 db "true",0ah,0dh,'$'      ;5
	string5 db "false",0ah,0dh,'$'
data ends
stack segment para stack'stack'
	db	256 dup(?)
stack ends                                 ;10
extra segment
	stringcopy db 256 dup(?)
extra ends
code segment
main 	proc	far                        ;15
   assume ds:data,es:extra,cs:code
start:
	sub ax,ax
	mov ax,data
	mov ds,ax                          ;20
	lea si,string1
	mov cx,14h
	movsb
	sub si,si
	sub di,di                          ;25
	mov cx,14h
	sub al,al
	mov ah,09h
	mov dx,si
	int 21h                            ;30
	mov dx,di
	int 21h        
find:	cmp byte ptr[si],'s'
	jz change                          
	inc si                             ;35
	loop find
then:	lea dx,string3
	int 21h        
	jmp begin                          
change:	lea dx,string2                     ;40    
	int 21h
	mov byte ptr[si],'S'
begin:  sub si,si          
	sub di,di                          
compare:mov cx,14h                         ;45 
	cld         
	repe cmpsb
	jnz differ                         
same:   lea dx,string4                     
	int 21h                            ;50         
	jmp exit
differ: lea dx,string5                     
	int 21h 
exit:	lea dx,string1
	int 21h                            ;55
	mov ah,4ch                          
	int 21h         
main endp
code ends                                  
	end start        	           ;60