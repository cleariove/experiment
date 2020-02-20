data segment
	storage	db	9 dup(?)
data ends
stack segment
	db 256 dup(?)
stack ends
code segment
	assume cs:code,ds:data,ss:stack
main proc far
start:
	mov 	ax,data
	mov	ds,ax
	mov	cx,08h
lop:	lea	bx,storage
	mov	ah,01h
	int	21h
	mov	[bx],al
	inc 	bx
	loop	lop
	mov	byte ptr[bx],'$'
	mov	ah,09h
	lea	dx,storage
	int	21h
	mov	ah,4ch
	int	21h
main endp
end	start
code ends
	