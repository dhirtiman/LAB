// 10 . write a program to do polynomial addition using linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
   float co;
   int expo;
   struct node *link;
};

struct node *insert_begin(struct node *head, float co, int expo)
{
   struct node *newnode = (struct node *)malloc(sizeof(struct node));
   newnode->co = co;
   newnode->expo = expo;
   newnode->link = NULL;

   if (head == NULL)
   {
      return newnode;
   }

   newnode->link = head;
   head = newnode;
   return head;
}

struct node *add(struct node *head, struct node *head1)
{
   struct node *temp, *temp1, *head2;
   temp = head;
   temp1 = head1;
   head2 = NULL;

   while (temp != NULL && temp1 != NULL)
   {
      if (temp->expo == temp1->expo)
      {
         head2 = insert_begin(head2, temp->co + temp1->co, temp->expo);
         temp = temp->link;
         temp1 = temp1->link;
      }
      else if (temp->expo > temp1->expo)
      {
         head2 = insert_begin(head2, temp->co, temp->expo);
         temp = temp->link;
      }
      else
      {
         head2 = insert_begin(head2, temp1->co, temp1->expo);
         temp1 = temp1->link;
      }
   }

   while (temp1 != NULL)
   {
      head2 = insert_begin(head2, temp1->co, temp1->expo);
      temp1 = temp1->link;
   }

   return head2;
}

struct node *create(struct node *head)
{
   int n, expo;
   float co;

   printf("Enter the number of terms (ascending order of exponents): ");
   scanf("%d", &n);
   for (int i = n; i > 0; i--)
   {
      printf("\nEnter the coefficient of term %d: ", i);
      scanf("%f", &co);
      printf("\nEnter the exponent of term %d: ", i);
      scanf("%d", &expo);
      head = insert_begin(head, co, expo);
   }
   printf("\n\n");
   return head;
}

int main()
{
   struct node *t, *p1, *p2, *sum;
   p1 = NULL;
   p2 = NULL;
   sum = NULL;

   printf("\nFirst Polynomial\n");
   p1 = create(p1);

   printf("\nSecond Polynomial\n");
   p2 = create(p2);

   sum = add(p1, p2);

   printf("\nResult: \n");
   for (t = sum; t != NULL; t = t->link)
   {
      printf("%.1f^%d ", t->co, t->expo);
      if (t->link)
      {
         printf("+");
      }
   }
}

/*
First Polynomial
Enter the number of terms (ascending order of exponents): 3

Enter the coefficient of term 3: 10

Enter the exponent of term 3: 0

Enter the coefficient of term 2: 5

Enter the exponent of term 2: 1

Enter the coefficient of term 1: 6

Enter the exponent of term 1: 2



Second Polynomial
Enter the number of terms (ascending order of exponents): 3

Enter the coefficient of term 3: 20

Enter the exponent of term 3: 0

Enter the coefficient of term 2: 5

Enter the exponent of term 2: 1

Enter the coefficient of term 1: 10

Enter the exponent of term 1: 2



Result:
30.0^0 +10.0^1 +16.0^2
*/