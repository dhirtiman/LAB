// 5. write a recursive program to find the greatest commom divisor(GCD) 
// of given numbers

#include <stdio.h>
#include <conio.h>

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
void main()
{
	int num1, num2, result;

	printf("\nEnter two numbers:");
	scanf("%d", &num1);
	scanf("%d", &num2);
	result = gcd(num1, num2);
	printf("GCD of %d and %d is %d", num1, num2, result);
}

/*
Enter two numbers:25 50
GCD of 25 and 50 is 25
*/
