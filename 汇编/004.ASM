data segment
	string	db "In 1990,the exchange rate was 8.1/$"
	num	db 0
	char	db 0
	other	db 0						
data ends
stack segment
		db 256 dup(?)
stack ends
code segment							
main proc far
	assume ds:data,cs:code,ss:stack
start:
	mov ax,data
	mov ds,ax						
	mov dx,offset string
	mov ah,09h						
	int 21h
	lea si,string
	mov cx,23h											;20
compare:cmp byte ptr[si],'0'
	jb adchar
	jnb number						
number:	cmp byte ptr[si],'9'
	jna adnum						
	ja chara
chara:	cmp byte ptr[si],'A'
	jb adother						
	jnb char1
char1:	cmp byte ptr[si],'Z'
	jna adchar
	ja next
next:	cmp byte ptr[si],'a'					
	jb adother
	jnb then
then:	cmp byte ptr[si],'z'
	jna adother
	ja adother						
adnum:	inc num
	inc si
	loop compare
	jmp exit
adother:inc other
	inc si							
	loop compare
	jmp exit
adchar:	inc char
	inc si
	loop compare
exit:	mov ah,4ch
	int 21h							
main endp
code ends							
	end start