section .bss
	Gradde	resb	4
	Ost	resb	1
	Mjolk	resb	4

	extern  _GetStdHandle@4
	extern  _WriteFile@20
	extern  _ExitProcess@4
section .text
	global _main

_main:
	mov	eax, [Mjolk]
	mov	ebx, 1
	Add	eax, ebx
	mov	[Mjolk], eax
Print:
	mov	ebp, esp
	sub	esp, 4

	push	-11
	call	_GetStdHandle@4
	mov	ebx, eax

	push	0
	lea	eax, [ebp - 4]
	push	eax
	push(message_end - message)
	push	message
	push	ebx
	call	_WriteFile@20

	push	0
	push	_ExitProcess@4
