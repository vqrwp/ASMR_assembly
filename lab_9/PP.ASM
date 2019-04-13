.386
.model Flat, C

public P1 

.code

p1:
	PUSH EBP
	MOV	EBP, ESP
	MOV EAX, 1 ; here is the future result
	MOV	ECX, [EBP + 8] ; N
	MOV	EBX, [EBP + 12] ; NF adress
	CALL M1
	POP EBP
	RET

M1:
	JECXZ REG_EXIT ; if CX == 0
	MUL ECX ; AX = AX * CX
	DEC ECX
	CALL M1

REG_EXIT:
	RET

END