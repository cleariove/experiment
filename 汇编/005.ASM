data segment
	num	db 4	dup(?)
	Save 	dw 1 	dup(?)
data ends
stack segment
	db 125 dup(?)                                
stack ends
code segment
	assume ds:data,ss:stack,cs:code
main proc far
start:
	mov 	ax,data
	mov 	ds,ax
lop:	lea	bx,num
	mov 	ah,01h
	int	21h
	cmp 	al,'0'
	jb	exit
	jnb	next
next:	cmp	al,'9'
	jna	sub1
	ja	change1
change1:cmp	al,'A'
	jb	exit
	jnb	change2
change2:cmp	al,'Z'
	jna	sub2
	ja	change3
change3:cmp	al,'a'
	jb	exit
	jnb	change4
change4:cmp	al,'z'
	jna	sub3
	ja	exit
sub3:	sub	al,61h
	jmp	enter
sub2:	sub	al,41h
	jmp	enter
sub1:	sub	al,30h
	jmp	enter
enter:	mov	[bx],al
	inc	bx
	loop	lop
	sub	ax,ax
	lea	bx,num
	mov	cl,04h
	mov	ah,[bx]
	shl	ah,cl
	inc	bx
	add	ah,[bx]
	inc	bx
	mov	al,[bx]
	shl	al,cl
	inc	bx
	add	al,[bx]
	mov	Save,ax                                  
exit:	mov	ah,4ch
	int	21h
main	endp
	code	ends
	end	start
	