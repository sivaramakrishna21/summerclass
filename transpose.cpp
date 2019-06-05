#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

void transpose(int a[100][100],int m,int n,int b[100][100])
{
	//int **b = (int **)malloc(sizeof(int *)*n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[j][i] = a[i][j];

		}

	}
	

}
int main()
{
	int m, n, a[100][100],b[100][100];
	scanf("%d%d", &m, &n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	}

	transpose(a, m, n,b);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%d ", b[i][j]);
		printf("\n");
	}
	getchar();
	getchar();
}
