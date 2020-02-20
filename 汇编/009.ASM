data	segment
	tip	db	'Do you want to continue?(Y/N)',0dh,0ah,"$"
	tip2	db	'See you next time!$'
data	ends
code segment
	assume cs:code,ds:data
main 	proc 	far
	mov	ax,data
	mov	ds,ax
repeat:
	mov	ax,0
	call	dec_bin
	call	print
	call	crlf
	lea	dx,tip
	mov	ah,09h
	int	21h
	mov	ah,01h
	int	21h
	cmp	al,'y'
	jz	repeat
	jnz	then
then:
	cmp	al,'Y'
	jz	repeat
	jnz	ending
ending:
	lea	dx,tip2
	mov	ah,09h
	int	21h
	call	crlf
	mov	ah,4ch
	int	21h
main 	endp
dec_bin proc	near
	sub	bx,bx
	sub	ax,ax
char_in:
	mov	ah,01h
	int	21h
	cmp	al,'0'
	jb	exit
	cmp	al,'9'
	ja	exit
	sub	al,30h
	cbw
	xchg	ax,bx
	mov	cx,10d
	mul	cx
	xchg	ax,bx
	add	bx,ax
	jmp	char_in
exit:	
	ret
dec_bin	endp
crlf	proc	near	
	mov	dl,0dh
	mov	ah,02h
	int	21h
	mov	dl,0ah
	int	21h
	ret
crlf	endp
print	proc	near
	mov	cx,10h
lop:	rol	bx,1
	jnc	zero
	mov	dl,31h
	jmp	show
zero:	mov	dl,30h
show:	mov	ah,02h
	int	21h
	loop	lop
	ret
print	endp
code	ends
	end	main