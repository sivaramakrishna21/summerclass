#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
void sort(int *,int );
int main()
{
	int size;
	scanf("%d", &size);
	int *array = (int *)malloc(sizeof(int)*size);
	for (int i = 0; i < size; i++)
		scanf("%d", &array[i]);
	sort(array,size);
	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);
	getchar();
	getchar();
}
void sort(int *array,int n)
{
	int i = 0, j = n - 1;
	for (i = 0; i < j; i++)
	{
		if (array[i] == 1)
		{
			while (j > i)
			{
				if (array[j] == 0)
				{
					array[j] = 1;
					array[i] = 0;
					break;
				}
				j--;
			}
		}
	}
}