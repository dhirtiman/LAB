// 5. write a recursive program to find the greatest commom divisor(GCD)
// of given numbers

#include <stdio.h>
#include <conio.h>

/*
include io and io

input two numbers
call gcd fn store the result

gcd fn:
  if(2nd number is 0)
	return 1st number
  else:
    return gcd with 2nd number as the first number , and 2nd number is mod between firsr and 2nd number

eg: 

  gcd( 10,20) -> 10
1. a = 10 , b = 20 , call(20,10%20) , 20,10 , got 10
2. a = 20 , b = 10 , call(10,20%10) , 10,10 , got 10
3. a = 10 , b = 10 , call(10,10%10) , 10,0  , got 10
4. a = 10 , b = 0 , here b is 0 so return a , 10

print the result 
*/

int gcd(int a, int b)
{
	if (b == 0)
		return a;
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
