#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int isSafe(int x, int y, int xlimit, int ylimit, int m, int n){
	if (x >= xlimit && x < m && y >= ylimit && y < n)
		return true;
	return false;
}

int printSpiral(int arr[100][100], int x, int y, int xlimit, int ylimit, int m, int n, int done, int total){
	int pos[8] = { 0, 1, 1, 0, 0, -1, -1, 0 }, c = 0;
	int xt = x, yt = y, flag = 0;
	while (c < 8){
		if (x == xt && y == yt){
			if (flag == 0){
				flag = 1;
				if (isSafe(x, y, xlimit, ylimit, m, n)){
					printf("%d ", arr[x][y]);
					done++;
				}
			}
			else
				break;
		}
		else{
			if (isSafe(x, y, xlimit, ylimit, m, n)){
				done++;
				printf("%d ", arr[x][y]);
			}
		}
		if (done == total)
			break;
		if (isSafe(x + pos[c], y + pos[c + 1], xlimit, ylimit, m, n)){
			x = x + pos[c];
			y = y + pos[c + 1];
		}
		else{
			c = c + 2;
			x = x + pos[c];
			y = y + pos[c + 1];
		}
	}
	return done;

}

int main(){
	int m, n;
	int arr[100][100];
	printf("enter m & n values\n");
	scanf("%d%d", &m, &n);
	int value = 1;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			arr[i][j] = value++;
	int total = m*n;
	printf("\n\n matrix:- \n");
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	int done = 0;
	printf("\n\nspiral :- \n");
	int xc = 0, yc = 0;
	int xlimit = 0, ylimit = 0;
	while (done < total){
		//printf("hii done=%d\n",done);
		done = printSpiral(arr, xc, yc, xlimit, ylimit, m, n, done, total);
		m--;
		n--;
		xlimit++;
		ylimit++;
		xc++;
		yc++;
	}
	//printf("hii");
	getchar();
	getchar();
	return 0;
}