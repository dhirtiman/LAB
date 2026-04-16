// 7.	Write a program to implement the Naïve (Brute Force) Pattern Matching 
// Algorithm.

#include <stdio.h>
#include <conio.h>
#include <string.h>

/*
include io and io andd string.h

declare two char arrays , 
two iterators for each array ,
two size store for each array 
one flag to check if found

input two str using gets(str) , text,pattern
extract strings lengths using 
  strlen(string)

iterate  i from 0  to texlen-patlen 
   iterate j from 0 to patlen-1 
    check if(text[i+j] != pattern[j]): meaning check if any of the characters dont match
       yes, break
    check if j == patlen-1 : we were abke to traverse whole pattern without interuption
     yes, print pattern found at index i , set flag = 1


if(flag=0):
  print pattern was not found anywhere

*/

void main()
{
    char text[100], pattern[50];
    int i, j, t_len, p_len, found = 0;

    // clrscr();

    printf("Enter the text: ");
    gets(text);

    printf("Enter the pattern: ");
    gets(pattern);

    t_len = strlen(text);
    p_len = strlen(pattern);

    for (i = 0; i <= t_len - p_len; i++)
    {
        for (j = 0; j < p_len; j++)
        {
            if (text[i + j] != pattern[j])
                break;
        }

        if (j == p_len)
        {
            printf("\nPattern found at position %d", i + 1);
            found = 1;
        }
    }

    if (!found)
        printf("\nPattern not found");

    getch();
}

/*
Enter the text: my name is harry
Enter the pattern: e is

Pattern found at position 7
*/