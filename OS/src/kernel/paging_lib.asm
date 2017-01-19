
[global write_cr3]
write_cr3:
	;prologue
	push ebp
	mov ebp, esp

	;take param and set in cpu reg
	mov eax, [ebp+8]
	mov cr3, eax

	;epilogue
	pop ebp
	retn
