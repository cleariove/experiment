data	segment
message	db	'This is a simple program of keyboard and disply'
	db	0dh,0ah,'Please strike the key!',0dh,0ah,'$'
data	ends
stack	segment para stack'stack'
	db	50 dup(?)
stack 	ends
code	segment
	assume	cs:code,ds:data,ss:stack
start:	
	mov	ax,data
	mov 	ds,ax
	mov	dx,offset message
	mov	ah,9
	int	21h
again:	mov	ah,1
	int	21h	
	cmp	al,1bh
	je	exit
	cmp	al,61h
	jc	nd
	cmp	al,7ah	
	ja	nd
	and	al,11011111b
nd:	mov	dl,al
	mov	ah,2
	int	21h
	jmp	again
exit:	mov	ah,4ch
	int	21h
code	ends
	end	start