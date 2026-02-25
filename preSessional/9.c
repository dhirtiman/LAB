// 9.	Write a program to implement Rabin-Karp Pattern Matching Algorithm.

#include <stdio.h>
#include <string.h>
#include <conio.h>

#define q 7

int hash(char *str, int len)
{
	int h = 0, i;
	for (i = 0; i < len; i++)
	{
		h = (h + str[i]) % q;
	}

	return h;
}

void rabinKarp(char text[], char pattern[])
{
	int i, j, k, pHash, tHash, match, plen, tlen, found = 0;
	plen = strlen(pattern);
	tlen = strlen(text);
	pHash = hash(pattern, plen);

	for (i = 0; i <= (tlen - plen); i++)
	{

		tHash = hash(text + i, plen);
		if (tHash == pHash)
		{
			match = 1;
			for (j = 0; j < plen; j++)
			{
				if (text[i + j] != pattern[j])
				{
					match = 0;
					break;
				}
			}
			if (match == 1)
			{
				found = 1;
				printf("Pattern found at index %d\n", i);
				
				printf("%s\n", text);
				for (k = 0; k < i; k++)
				{
					printf(" ");
				}
				printf("^\n");
			}
		}
	}
	if (!found)
		printf("\nPattern not found");
}

void main()
{

	char text[100], pattern[50];

	printf("Enter the text: ");
	gets(text);

	printf("Enter the pattern: ");
	gets(pattern);

	rabinKarp(text, pattern);
	getch();
}

/*

Enter the text: my name is harry
Enter the pattern: harry
Pattern found at index 11
my name is harry
		   ^

Enter the text: my name is
Enter the pattern: haryy

Pattern not found

*/