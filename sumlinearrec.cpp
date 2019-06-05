#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
long sumbylinearrecursion(int array[], int size)
{
	if (size ==0)
		return 0;
	if (size == 1)
		return array[0];
	long sum = 0;
	sum += array[0]+sumbylinearrecursion(array + 1, size - 1);
	return sum;
}
int main()
{
	int array[] = { 1, 2, 3, 4, 5,6 };
	printf("%d",sumbylinearrecursion(array, 6));
	return 0;
}
