.386
.model Flat,C

public P2

.code
P2:                                        ;        4  4  4
		PUSH	EBP ; current place in the stack, EBP N NF
		MOV		EBP, ESP  ; go to current position in stack
		MOV		ECX, [EBP + 8] ; get N
		MOV		EBX, [EBP + 12] ; get address of NF

		CMP		ECX, 0 ; if CX != 0, N != 0
		JE		RET_1 ; CX == 0
		 
		DEC		ECX ; CX--, because without it we get stackoverflow

		PUSH	EBX ; address of NF, result
		PUSH	ECX ; all numbers from N - 1 to 1
		CALL	P2 ; in stack: NF 5, NF 4, NF 3, NF 2, 1 1, NF = 1

		ADD ESP, 8
		INC		ECX ; N
		MOV		EAX, DWORD PTR [EBX] ; AX = 1 = NF
		MUL		ECX ; CX * AX = CX * NF

		MOV		DWORD PTR [EBX], EAX ; result
		JMP		EXIT

	RET_1:
		MOV		DWORD PTR [EBX], 1 ; NF = 1, answer is in EBX

	EXIT:
		POP		EBP
		RET		

END