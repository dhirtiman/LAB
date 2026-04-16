// 6. Write a program to perform string operations using built-in string functions:
//  concatenation, comparison, copy, and substring extraction.

#include <stdio.h>
#include <conio.h>
#include <string.h>

/*
include io and io and string.h not strings.h

declare 4 char arrays of arbritary sizes,
str1,str2,str3,sub
 two ints, pos and len 

input str1 and str2 using, gets(string)

1. demo string copying: 
  copy str1 to str3(undefined) 
  using, strcpy(str3,str1);
  print str3 using %s
3. demo string comparison:
  check if str3 and str2 are equal
   using strcmp(str3,str2) -> res
    if res = 0 , they are equal
	else not equal 
4.  substring extraction
  input starting postion and length of the sub string
  in pos and len

  extract substring into sub
  using strcpy(sub,str3+pos-1,len): , 
  str3+pos-1 means treat the str3 string from pos-1 index
  eg:  str3 = "bookworm" , pos = 5 , len = 4 ,
  so -> str3+pos-1 = "worm" sub = "worm"

  set sub[len] = '\0' 


*/

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
