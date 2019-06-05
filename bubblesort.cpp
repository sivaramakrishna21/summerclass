#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
void sort(int *, int);
int main()
{
	int size;
	scanf("%d", &size);
	int *array = (int *)malloc(sizeof(int)*size);
	for (int i = 0; i < size; i++)
		scanf("%d", &array[i]);
	sort(array, size);
	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);
	getchar();
	getchar();
}
void sort(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i]<a[j])
			{
				int c = a[i];
				a[i] = a[j];
				a[j] = c;
			}
		}
	}
}