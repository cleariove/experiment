data	segment
	tip	db	"Please input:$"
data	ends
stack	segment
		db	256 dup(?)
stack	ends
code	segment
main	proc	far
	assume	ds:data,cs:code,ss:stack
start:
	mov	ax,data
	mov	ds,ax
	mov	dx,offset tip
	mov	ah,09h
	int	21h
	call	input
	call	crlf
	call	bin_dec
exit:	
	mov	ah,4ch
	int	21h
main	endp

input	proc	near
	sub	bx,bx
	mov	cx,04h
newchar:
	push	cx
	mov	ah, 1
	int	21h
	sub	al, 30h
	cmp	al, 0ah
	jb	add_to
	sub	al,07h           
	cmp	al, 10h
	jb	add_to
	sub	al,20h
	cmp	al, 10h
	jb	add_to
add_to:
	mov	cl, 04h
	shl	bx, cl
	sub	ah,ah
	add	bx, ax
	pop	cx
	loop	newchar
	ret
input	endp

bin_dec	proc	near
	mov	cx,10000d
	call	div_ten
	mov	cx,1000d
	call	div_ten
	mov	cx,100d
	call	div_ten
	mov	cx,10d
	call	div_ten
	mov	cx,01d
	call	div_ten
	ret
bin_dec	endp

div_ten	proc	near
	mov	ax, bx
	sub	dx, dx
	div	cx
	mov	bx, dx
	mov	dl, al
	add	dl, 30h
	mov	ah, 02h
	int	21h
	ret
div_ten	endp

crlf	proc	near
	mov	ah,02h
	mov	dl,0ah
	int	21h
	mov	dl,0dh
	int	21h
	ret
crlf	endp

code	ends
end	start