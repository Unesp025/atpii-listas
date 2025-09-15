#include<stdio.h>
#include<stdlib.h>

char *questao1 (char str1[], char str2[])
{
	char *str3 = (char *) malloc(sizeof(char) * 21);
	for (int i = 0; i < 10; i++)
	{
		str3[i] = str1[i];
	}
	for (int i = 10; i < 20; i++)
	{
		str3[i] = str2[i-10];
	}
	str3[20] = '\0';
	return str3;
}

int main()
{
	char str1[] = "abcdfghijk";
	char str2[] = "lmnopqrstu";

	char *str3 = questao1(str1, str2);
	printf("\n%s\n", str3);

	return 0;
}
