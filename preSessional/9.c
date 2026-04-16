// 9.	Write a program to implement Rabin-Karp Pattern Matching Algorithm.

#include <stdio.h>
#include <string.h>
#include <conio.h>

/*
include io,io and string.h
define a preprocessor constant , q = 6
 as #define q 7 , this is a prime number we'll use

define a hash fucntion , hash(char *stringpointer,int len) -> int h
 inside:
	set h = 0
	iterate i from 0 to len-1 , (each character of the string)
	 add to h , character%q , str[i]%q
	return h
define rabinKarp fn , rabinKarp(char array(char text[]) , char pattern[]):
   define iterators i,j for each string
   extract len for each string , plen,tlen 
   store hash of pattern in phash 

   iterate i from 0 to tlen-plen
     generate hash of text+i , thash
	 if(thash==phash):
	   set match = 1
	   iterate j from 0 to plen-1
	     if(text[i+j]!=text[j])
		   set match = 0
		   break
	   if(match):
	     print pattern found at index i 
		 set found = 1
	
	if(not found)
	  print pattern not found anywhere

*/

#define q 7

int hash(char *str, int len)
{
	int h = 0, i;
	for (i = 0; i < len; i++)
	{
		h += str[i] % q;
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