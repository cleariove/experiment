datas	segment
	data	db	24,18,-8,-16,66,56,86,6,10,98
	count	db	10,10
datas	ends
codes	segment
	assume	cs:codes,ds:datas,es:datas
start:
	mov	ax,datas
	mov	ds,ax
	mov	es,ax
	mov	bl,1 
loop1: 
	cmp	bl,0 
	je	dataout 
	xor	bl,bl
	mov	cl,count 
	dec	cl  
	push	cx 
	lea	di,data 
loop2: 
	mov	al,[di] 
	cmp	al,[di+1] 
	jle	loop3
	xchg	[di+1],al
	mov	[di],al 
	mov	bl,1 
loop3: 
	inc	di  
	loop	loop2 
	pop	cx
	mov	count,cl 
	jmp	loop1 
dataout:
	mov	cl,10
	lea	di,data
next:
	mov	ax,0 
	mov	bh,2
	mov	al,[di] 
	cmp	al,0 
	jge	non
	neg	al 
	push	ax	
	mov	ah,2 
	mov	dl,'-' 
	int	21h 
	pop	ax 
non:
	xor	ah,ah 
	div	count+1 
	mov	dh,ah
	cmp	al,0 
	je	single 
	add	al,30h 
	mov	dl,al
	mov	ah,2 
	int	21h 
single:
	mov	al,dh 
	xor	ah,ah
	add	ax,3030h 
	mov	dl,al 
outp:
	mov	ah,2
	int	21h 
	dec	bh
	jz	xt  
	mov	dl,bl 
	jmp	outp 
xt:
	dec	cl 
	jz	done 
	inc	di 
	jmp	next
done:
	mov	ah,1
	int	21h  
	mov	ah,4ch
	int	21h
codes ends 
end start
