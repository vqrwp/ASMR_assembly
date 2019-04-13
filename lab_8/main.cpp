// ConsoleApplication8.cpp: определяет точку входа для консольного приложения.
//

#include <conio.h>
#include <iostream>
#include <tchar.h>
#include <SDKDDKVer.h>

using namespace std;




int _tmain(int argc, _TCHAR* argv[])
{
    unsigned char mas[8][8] = {
            {1,1,1,1,1},
            {2,2,2,2,2},
            {3,3,3,3,3},
            {4,4,4,4,4},
            {5,5,5,5,5}
    };

	for(int i = 0; i < 5; i++){

		for(int j = 0; j < 5; j++){
		printf("%d ", mas[i][j]);
		}
		printf("\n");
	}
		printf("\n");

	_asm{
            MOV  SI, OFFSET A
            MOV  DI, SI
            MOV  CX, 5              ; В регистры CX и DX заносим размеры матрицы
            ADD  DI, 5              ; Переходим к второй строке матрицы
            DEC  CX                 ; Пропускаем клетку, лежащую на главной диагонали, которая не изменяется

            ROW:
            MOV BX, DI
            MOV BH, CL 		    	; Сохраняем размеры матрицы (bH = CL, bL = DI)

            COLUMN:
            INC  SI
            XCHG  AL, A[SI]
            XCHG  AL, A[DI]
            XCHG  AL, A[SI]         ; Меняем A[DI], A[SI]
            ADD  DI, 5		 		; Переходим к следующей строке
            LOOP COLUMN		 		; Обмениваем целиком строку и столбец

            MOV CL, BH
            MOV BH, 0				; Обнуляем размер матрицы

            MOV DI, BX			    ; Извлекаем сохраненные регистры
            ADD  DI, 5
            INC  DI	        	    ; Переходим к следующему столбцу, пропуская клетку, лежащую на главной диагонали
            MOV  SI, DI
            SUB  SI, 5			    ; Переходим к следующей строке (вычитаем из си 5)
            LOOP ROW
    }

	for(int i = 0; i < 5; i++){
		printf("\n");
		for(int j = 0; j < 5; j++){
		printf("%4d", mas[i][j]);
		}
	}

	printf("\n");
	system ("pause");
	return 0;
}
