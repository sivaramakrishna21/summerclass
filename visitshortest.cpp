#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int ischeck(int startrow, int startcol, int m, int n, int maze[100][100])
{
	if (startrow < 0 || startrow >= m || startcol < 0 || startcol >= n || maze[startrow][startcol] == 0)
		return 0;
	return 1;
}
int solvemaze(int maze[100][100], int m, int n, int startrow, int startcol, int endrow, int endcol, int sol[100][100], int len)
{
	if (startrow == endrow&&startcol == endcol)
	{
		int i;
		for (i = len - 1; i >= 0; i--)
		{
			if (sol[i][0] == sol[0][0] && sol[i][1] == sol[0][1])
				break;
		}
		if (i == -1)
			i = 0;
		for (int j = i; j < len; j++)
			printf("%d %d\n", sol[j][0], sol[j][1]);
		return 1;
	}
	if (ischeck(startrow + 1, startcol, m, n, maze))
	{
		maze[startrow + 1][startcol] = 0;
		sol[len][0] = startrow + 1;
		sol[len][1] = startcol;
		int c = solvemaze(maze, m, n, startrow + 1, startcol, endrow, endcol, sol, len + 1);
		
	}
	if (ischeck(startrow, startcol + 1, m, n, maze))
	{
		maze[startrow][startcol + 1] = 0;
		sol[len][0] = startrow;
		sol[len][1] = startcol + 1;
		int c = solvemaze(maze, m, n, startrow, startcol + 1, endrow, endcol, sol, len + 1);
		

	}
	if (ischeck(startrow - 1, startcol, m, n, maze))
	{
		maze[startrow - 1][startcol] = 0;
		sol[len][0] = startrow - 1;
		sol[len][1] = startcol;
		int c = solvemaze(maze, m, n, startrow - 1, startcol, endrow, endcol, sol, len + 1);

		
	}
	if (ischeck(startrow, startcol - 1, m, n, maze))
	{
		maze[startrow][startcol - 1] = 0;
		sol[len][0] = startrow;
		sol[len][1] = startcol - 1;
		int c = solvemaze(maze, m, n, startrow, startcol - 1, endrow, endcol, sol, len + 1);
		
	}
	return 0;
}
int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	int maze[100][100], sol[100][100];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &maze[i][j]);
		}
	}
	printf("hi");
	int startrow, startcol, endrow, endcol;
	scanf("%d%d%d%d", &startrow, &startcol, &endrow, &endcol);
	sol[0][0] = startrow;
	sol[0][1] = startcol;
	int c = solvemaze(maze, m, n, startrow, startcol, endrow, endcol, sol, 1);
	if (c == 0)
		printf("not possible");
	getchar();
	getchar();
}
