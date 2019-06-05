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
void sort(int *a, int len)
{
	int count = 0, count1 = 0;
	for (int i = 0; i < len; i++)
	{
		if (a[i] == 0)
			count++;
		else if (a[i] == 1)
			count1++;
		a[i] = 2;
	}
	for (int i = 0; i < count; i++)
		a[i] = 0;
	for (int i = count; i < count+count1; i++)
		a[i] = 1;
}