data segment
	tip	db	'Please enter a string and you can end the subject with ?',0dh,0ah,"$"
data ends
code segment
	assume ds:data,cs:code
start:
	mov	ax,data
	mov	ds,ax
	lea	dx,tip
	mov	ah,09h
	int 	21h
lop:	mov	ah,07h
	int	21h
	cmp	al,'?'
	je	exit
	cmp	al,'A'
	jb	show
	jnb	then
then:	cmp	al,'Z'
	jna	change
	ja	show
change:	add	al,20h
show:	mov	dl,al
	mov	ah,02h
	int	21h
	jmp	lop
exit:	mov	ah,4ch
	int	21h
code ends
end start
	