// 6. Write a program to perform string operations using built-in string functions:
//  concatenation, comparison, copy, and substring extraction.

#include <stdio.h>
#include <conio.h>
#include <string.h>

void main()
{
	char str1[50], str2[50], str3[50];
	char sub[50];
	int pos, len;

	printf("\nEnter first string:");
	gets(str1);

	printf("\nEnter second string:");
	gets(str2);

	// String copy
	strcpy(str3, str1);
	printf("\nCopied string (str3): %s", str3);

	// string comparison
	if (strcmp(str3, str2) == 0)
		printf("\nStrings are equal");
	else
		printf("\nStrings are not equal");

	// SubString extraction
	printf("\nEnter starting position of substring:");
	scanf("%d", &pos);

	printf("Enter length of substring: ");
	scanf("%d", &len);

	strncpy(sub, str3 + pos - 1, len);
	sub[len] = '\0';

	printf("Extracted substring: %s", sub);
}

/*
Enter first string:book

Enter second string:book

Copied string (str3): book
Strings are equal
Enter starting position of substring:3
Enter length of substring: 2
Extracted substring: ok
*/
