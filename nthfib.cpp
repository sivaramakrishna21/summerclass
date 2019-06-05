#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int fibn(int a[2][2], int n)
{
	int an[2][2] = { 0, 1, 1, 1 };
	if (n == 0)
		return 0;
	if (n == 1)
	{
		return a[1][1];
	}
	int k=fibn(a, n / 2);
	int b1 = a[0][0], b2 = a[1][0], b3 = a[0][1], b4 = a[1][1];
	a[0][0] = b1*b1 + b3 * b2;
	a[0][1] = b1*b3 + b3*b4;
	a[1][0] = b2*b1 + b4*b2;
	a[1][1] = b2*b3 + b4*b4;
	if (n % 2 == 1)
	{
		int b1 = a[0][0], b2 = a[1][0], b3 = a[0][1], b4 = a[1][1];

		a[0][0] = b1*an[0][0] + b3*an[1][0];
		a[0][1] = b1*an[0][1] + b3*an[1][1];
		a[1][0] = b2*an[0][0] + b4*an[1][0];
		a[1][1] = b2*an[0][1] + b4*an[1][1];
	}
	return a[1][1];
}
int main()
{
	int a[2][2] = { 0, 1, 1, 1 }, x[2][1] = { 0, 1 }, n,oddcount=0;
	scanf("%d", &n);
	
	int c=fibn(a,  n);
	printf("%d",c);
	getchar();
	getchar();
}
