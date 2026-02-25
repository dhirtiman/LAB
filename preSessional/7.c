// 7.	Write a program to implement the Naïve (Brute Force) Pattern Matching 
// Algorithm.

#include <stdio.h>
#include <conio.h>
#include <string.h>

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