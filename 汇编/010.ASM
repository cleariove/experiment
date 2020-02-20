data	segment
	tip1	db	'Please	input:$'
	initial	db	128	dup(?)
	secret	db	128	dup(?)
	star	db	"*"
data	ends
code	segment
main	proc	far
	assume	ds:data,cs:code
start:
	mov	ax,data
	mov	ds,ax
	mov	dx,offset tip1
	mov	ah,09h
	int	21h
	mov	bx,offset initial
	sub	si,si
	sub	cx,cx
begin:	
	call	input                                      
	
reveal:	
	call	cipher
	call	crlf
	mov	dx,offset secret
	mov	ah,09h
	int	21h
exit:
	mov	ah,4ch 
	int	21h
main	endp

	
input	proc	near
import:	
	mov	ah,07h
	int	21h
	cmp	al,0dh
	je	ending
	jne	reserve
reserve:
	mov	[bx+si],al
	inc	si
	inc	cx
	mov	dl,star                                   
	mov	ah,02h                           
	int	21h 
	jmp	import
ending:	
	mov	dl,'$'
	mov	[bx+si],dl
	ret
input	endp

cipher	proc	near
	sub	si,si
	mov	di,offset secret
lop:	
	mov	dl,[bx+si]
	cmp	dl,' '
	jne	change
	je	next
change:	
	add	dl,04h
next:	
	mov	[di],dl	
	inc	si
	inc	di
	loop	lop
	mov	dl,'$'
	mov	[di],dl
	ret
cipher	endp

crlf	proc	near
	mov	dl,0dh
	mov	ah,02h
	int	21h
	mov	dl,0ah
	int	21h
	ret
crlf	endp

code	ends
end	start