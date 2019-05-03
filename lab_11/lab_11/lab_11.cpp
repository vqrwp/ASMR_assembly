// lab_11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

extern "C" int DlinaStroki(char *s);
extern "C" char *CopyStr(char *s1, char *s2, int L);
extern "C" int DelProbel(char *s);

int main()
{
	char str1[80] = "    1234567 ";
	char str2[80] = "\0";
	char *tempStr;
	int len1, len2;

	len1 = DlinaStroki(str1);
	len2 = DlinaStroki(str2);

	printf("Len('%s') =  %d\n", str1, len1);
	printf("Len('%s') =  %d\n\n", str2, len2);

	tempStr = CopyStr(str1, str2, len1);

	printf("Given address: %p\n", tempStr);
	printf("Address str: %p\n", str2);

	printf("Source : '%s'\n", str1);
	printf("Copy : '%s'\n\n", str2);

	int n = DelProbel(str1);
	printf("String :'%s'\nLen = %d",str1,n);
	return 0;
}