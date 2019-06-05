/#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

void print(int prev[100], int current, int limit)
{
	char b[] = { '0','1', '2', 'E', 'h', '5', '9', 'L', '8', '6' };
	if (current == limit - 1)
	{
		int flag = 0;
		for (int i = 0; i < limit - 1; i++)
		{
			if (prev[i] == 0 && flag == 0)
				continue;
			else
			{
				flag = 1;
				printf("%c", b[prev[i]]);
			}
		}
		printf("\n");
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			prev[current] = i;
			print(prev, current + 1, limit);
		}

	}

}
int main()
{
	int n;
	scanf("%d", &n);
	int prev[100], current = 0;
	print(prev, current, n);

	getchar();
	getchar();
}
