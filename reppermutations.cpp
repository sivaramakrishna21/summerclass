/*#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int check(int prev[100], int i, int current,int a[100])
{
	int count = 0,count1=0;
	for (int j = 0; j < current; j++)
	{
		if (prev[j] == i)
			count++;
	}
	for (int k = 0; k < 4; k++)
	{
		if (a[k] == i)
			count1++;
	}
	if (count1>count)
	return i;
	return 0;
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
			int c = check(prev, a[i], current,a);
			if (c == 0)
				continue;
			else{
				prev[current] = a[i];
				for (int p = i + 1; p < len; p++)
				{
					if (a[i] == a[p])
						i++;
				}
			}
			printper(a, len, current + 1, prev);
		}
	}
}
int main()
{
	int a[] = { 1, 4 ,3,2}, len = 4, current = 0;
	int b[1000], c[10] = { 0 };
	int n = 4;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i]>a[j])
			{
				int c = a[i];
				a[i] = a[j];
				a[j] = c;
			}
		}
	}
	printper(a, len, current, b);

	getchar();
	getchar();
}
*/
