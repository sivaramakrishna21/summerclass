#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
long apowern(int a, int n)
{
	if (n < 0)
		return -1;
	if (n == 1)
		return a;
	long sum = 1;
	int power = apowern(a, n / 2);
	sum = power*power;
	sum = n % 2 ? sum*a : sum;
	return sum;
}
int main()
{
	printf("%d", apowern(3, 5));
	return 0;
}
