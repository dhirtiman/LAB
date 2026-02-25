// 12 . write a program to convert infix to postfix using stack.

#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x)
{
   stack[++top] = x;
}

char pop()
{
   if (top == -1)
      return -1;
   return stack[top--];
}

char peek()
{
   return stack[top];
}

int priority(char ch)
{
   if (ch == '(')
      return 0;
   if (ch == '^')
      return 3;
   if (ch == '*' || ch == '/' || ch == '%')
      return 2;
   if (ch == '+' || ch == '-')
      return 1;
   return 0;
}

int main()
{
   char exp[100];
   char *e, x;
   printf("Enter the infix expression: ");
   scanf("%s", exp);
   e = exp;

   while (*e != '\0')
   {
      if (isalnum(*e))
         printf("%c", *e);
      else if (*e == '(')
         push(*e);
      else if (*e == ')')
      {
         while ((x = pop()) != '(')
         {
            printf("%c", x);
         }
      }
      else
      {
         while (priority(peek()) >= priority(*e))
         {
            printf("%c", pop());
         }
         push(*e);
      }
      e++;
   }
   while (top != -1)
   {
      printf("%c", pop());
   }
   printf("\n");
   return 0;
}

/*
Enter the infix expression: (a^2+b^2+(2*a*b))
a2^b2^+2a*b*+
*/