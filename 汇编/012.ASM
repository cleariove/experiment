data	segment
	array	dw	100,30,78,99,15,1,66,54,189,256
data	ends

stack	segment
		dw	256	dup(?)
stack	ends

code	segment
	assume	ds:data,cs:code,ss:stack
start:
	mov	ax,data
	mov	ds,ax
	mov	cx,10
	dec	cx
loop1:
	mov	dx,cx
	lea	bx,array
loop2:     
	mov	ax,[bx]
	cmp	ax,[bx+2]
	jge	continue
	xchg	ax,[bx+2]
	mov	[bx], ax
continue:
 	add	bx, 2 
	loop	loop2
	mov	cx,dx
	loop	loop1
	mov	ah,4ch
	int	21h

code	ends
end	start



