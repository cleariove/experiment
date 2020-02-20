data segment
	array	db	'8 8 8 8 8 8 8 8',0dh,0ah,"$"
	num	dw	0
	count	dw	0
data ends
stack segment
		db	256 dup(?)
stack ends	
code segment
	assume	cs:code,ds:data,ss:stack
start:
	mov	ax,data
	mov	ds,ax
	mov	cx,0fh
space:	mov	dl,20h
	cmp	num,0
	jz	show
	dec	num
	mov	ah,02h
	int	21h
	jmp	space
show:	lea	dx,array
	mov	ah,09h
	int	21h
	inc	count
	mov	ax,count
	mov	num,ax
	loop	space
exit:	mov	ah,4ch
	int	21h
code ends
end	start
	