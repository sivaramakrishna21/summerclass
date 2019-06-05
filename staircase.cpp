/*#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
int stair(int c, int n,int k,int *str,int index)
{
	int ways = 0;
	if (c == n)
	{
		for (int i = 0; i < index; i++)
		{
			printf("%d", str[i]);
		}
		printf("\n");
		return 1;
	}

	for (int i = 1; i <= k; i++)
	{
		int t = c + i;
		if (t <= n)
		{
			str[index++] = i ;
			ways += stair(c + i, n, k, str, index);
			index--;
		}
	}
}
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	int ways = 0;
	//char *str = (char *)malloc(sizeof(char)*n);
	int str[100];
	for (int i = 1; i<= k; i++)
	{
		printf("dhf");
		str[0] = i ;
		ways += stair(i, n, k, str, 1);
	}
	//int ways = stair(n, k);
	printf("%d", ways);
	getchar();
	getchar();
}*/
