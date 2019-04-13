// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
extern "C" void P1(int N, int *g); // function from another file
extern "C" void P2(int N, int *g); // function from another file

int N = 6, NF = 7; // NF - result, N - factorial
int _tmain(int argc, _TCHAR* argv[])
{
	P2(N, &NF);
	printf("%d", NF);
	return 0;
}

