.386
.MODEL FLAT,C

PUBLIC DlinaStroki
.CODE
DlinaStroki:
	PUSH EBP
	MOV EBP,ESP
	PUSH EDI
	PUSH ESI

	XOR EAX,EAX
	MOV EBX, [EBP+8]			;������
	JMP M1
	
	MOV ESI, EDI
	MOV AL, 0

	CLD
	MOV ECX, -1
	REPME SCASB
	DEC EDI
	SIB EDI, ESI

	MOV EAX, EDI

	POP ESI
	POP EDI
	POP EBP
	RET
END