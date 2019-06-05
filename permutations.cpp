/*#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int check(int prev[100], int i, int current)
{
	for (int j = 0; j < current; j++)
		if (prev[j] == i)
			return 0;
	return i;
}
void printper(int a[100], int len, int current, int prev[100])
{
	if (len == current)
	{

		for (int i = 0; i <len; i++)
			printf("%d", prev[i]);
		printf("\n");
	}
	else
	{
		for (int i = 0; i < len; i++)
		{
			int c = check(prev, a[i], current);
			if (c == 0)
				continue;
			else
				prev[current] = a[i];
			printper(a, len, current + 1, prev);
		}

	}
}
int main()
{
	int a[] = { 1, 2, 3, 4 },len=4,current=0;
	int b[1000];
	printper(a, len, current,b);
	getchar();
	getchar();
}*/

