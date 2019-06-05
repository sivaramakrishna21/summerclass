/*#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<malloc.h>
void writezeros(char *);
void tolower(char *);
void insertdata(char *, int a[10][10],struct cell cell1[10][10]);
void getdata(char *, int a[10][10]);
int getnumber(char *);
void exportdata(char *, int a[10][10],struct cell cell1[10][10]);
void printdata(int a[10][10]);
char *getfilename(char *);
void importdata(char *, int a[10][10]);
struct cell{
	int rows, cols;
};
int main()
{

	char *str = (char *)malloc(sizeof(char));
	int a[10][10] = { 0 };
	char ch[10][10];
	struct cell cell1[10][10];
	//printf("%d", cell1[0][0]);
	while (1)
	{
		gets(str);
		tolower(str);
		if (str[0] == 's'&&str[1] == 'e'&&str[2] == 't'&&str[3] == ' ')
		{
			//printf("hi");
			insertdata(str, a,cell1);
		}
		else if (str[0] == 'g'&&str[1] == 'e'&&str[2] == 't'&&str[3] == ' ')
		{
			getdata(str, a);
		}
		else if (strcmp(str, "print") == 0)
		{
			printdata(a);
		}
		else if (str[0] == 'e'&&str[1] == 'x'&&str[2] == 'p'&&str[3] == 'o'&&str[4] == 'r'&&str[5] == 't')
		{
			exportdata(str, a,cell1);
		}
		else if (str[0] == 'i'&&str[1] == 'm'&&str[2] == 'p'&&str[3] == 'o'&&str[4] == 'r'&&str[5] == 't')
		{
			importdata(str, a);
		}
		else if (str[0] == 'e'&&str[1] == 'x'&&str[2] == 'i'&&str[3] == 't')
		{
			break;
		}


	}
}
void tolower(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'A'&&str[i] <= 'Z')
			str[i] = str[i] - 'A' + 'a';
	}
}
void insertdata(char *str, int a[10][10],struct cell cell1[10][10])
{

	int i, count = 0, j;
	//printf("hii");
	char *out = (char *)malloc(sizeof(char) * 10000);
	for (i = 0; str[i] != ' '; i++);
	for (j = i; str[j] == ' '; j++);
	//printf("%c %c", str[j], str[j + 1]);
	int c = str[j] - 'a';
	int row = str[j + 1] - '0' - 1;
	if (str[strlen(str) - 1] <= '9'&&str[strlen(str) - 1] >= '0'&&str[strlen(str) - 2] >= 'a'&&str[strlen(str) - 2] <= 'z')
	{
		
		int row1 = str[strlen(str) - 1] - '0'-1;
		int col1 = str[strlen(str) - 2] - 'a';
		cell1[row1][col1].rows = row;
		cell1[row1][col1].cols = c;
		printf("%d %d", cell1[row1][col1].rows, cell1[row1][col1].cols);
		a[row][c] = a[row1][col1];
	}
	else{
		int num = getnumber(str);
		//printf("num=%d ", num);
		a[row][c] = num;
	}
}

int getnumber(char *str)
{
	int i, j, num = 0;
	for (i = 0; str[i] != '='; i++);
	for (j = i + 1; str[j] != '\0'; j++)
	{
		num = num * 10 + (str[j] - '0');
		//printf("  %d", num);
	}
	return num;
}
void getdata(char *str, int a[10][10])
{

	int i, j, count = 0, value;
	char *out = (char *)malloc(sizeof(char) * 10000);

	for (i = 0; str[i] != ' '; i++);
	for (j = i; str[j] == ' '; j++);
	int c = str[j] - 'a';
	int row = str[j + 1] - '0' - 1;
	printf("%d", a[row][c]);

}
void printdata(int a[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}

}
void exportdata(char *str, int a[10][10],struct cell cell1[10][10])
{
	char *filename = (char *)malloc(sizeof(char) * 1000);
	filename = getfilename(str);
	FILE *fp;
	fp = fopen(filename, "w");
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			fprintf(fp, "%d", a[i][j]);
			//printf("%d %d", cell1[i])
			if (cell1[i][j].rows >= 0 && cell1[i][j].rows <= 10)
			{
				printf("hi");
				fprintf(fp, "%c", cell1[i][j].cols + 'A');
				fprintf(fp, "%d", cell1[i][j].rows);
				
			}
			fputc(',', fp);
		}
		fprintf(fp, "%s", "\n");
	}
	fclose(fp);
}
char *getfilename(char *str)
{
	char *filename = (char *)malloc(sizeof(char) * 1000);
	int len = 0, i, j;
	for (i = 0; str[i] != ' '; i++);
	for (j = i; str[j] == ' '; j++);
	for (i = j; str[i] != '\0'&&str[i] != '.'; i++)
		filename[len++] = str[i];
	filename[len++] = '.';
	filename[len++] = 'c';
	filename[len++] = 's';
	filename[len++] = 'v';
	filename[len++] = '\0';
	puts(filename);
	return filename;
}
void importdata(char *str, int a[10][10])
{
	char *filename = (char *)malloc(sizeof(char) * 1000);
	filename = getfilename(str);
	FILE *fp;
	fp = fopen(filename, "r");
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			fscanf(fp, "%d", &a[i][j]);
			//printf("%d ", a[i][j]);
			if (fgetc(fp) != ',')
			{
				fseek(fp, -1, SEEK_CUR);
			}
		}
		//printf("\n");
		fgetc(fp);
	}
}*/