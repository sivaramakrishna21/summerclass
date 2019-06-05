#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
printf("%d", apowernbyrecursion(3, 5));
return 0;
}
long apowernbyrecursion(int a, int n)
{
	if (n < 0)
		return -1;
	if (n == 1)
		return a;
	long sum =a*apowernbyrecursion(a,n-1) ;
	return sum;
}

