#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int m, n;
int arr[100][100];
int done = 0, xlimit = 0, ylimit = 0;
int pos[8] = { 0, 1, 1, 0, 0, -1, -1, 0 }, c = 0, flag = 0;
int total;
int isSafe(int x, int y){
	if (x >= xlimit && x < m && y >= ylimit && y < n)
		return true;
	return false;
}
int xt, yt;
void printSpiral(int x, int y){
	if (x == xt && y == yt){
		if (flag == 0){
			flag = 1;
			if (isSafe(x, y)){
				printf("%d ", arr[x][y]);
				done++;
			}
		}
		else
			return;
	}
	else{
		if (isSafe(x, y)){
			done++;
			printf("%d ", arr[x][y]);
		}
	}
	if (done == total)
		return;
	if (isSafe(x + pos[c], y + pos[c + 1])){
		printSpiral(x + pos[c], y + pos[c + 1]);
	}
	else{
		c = c + 2;
		printSpiral(x + pos[c], y + pos[c + 1]);
	}
}

int main(){
	printf("enter m & n values\n");
	scanf("%d%d", &m, &n);
	int value = 1;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			arr[i][j] = value++;
	total = m*n;
	printf("\n\n matrix:- \n");
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	printf("\n\nspiral :- \n");
	int xc = 0, yc = 0;
	while (done < total){
		//printf("hii done=%d\n",done);
		int xt = xc, yt = yc;
		printSpiral(xc, yc);
		m--;
		n--;
		xlimit++;
		ylimit++;
		c = 0;
		xc++;
		yc++;
		flag = 0;
	}
	getchar();
	getchar();
	return 0;
}