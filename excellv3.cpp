#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<malloc.h>
void writezeros(char *);
void tolower(char *);
void insertdata(char *, int a[10][10], char opeStrings[100][100]);
void getdata(char *, int a[10][10]);
int getnumber(char *);
void exportdata(char *, int a[10][10], char opeStrings[100][100]);
void printdata(int a[10][10]);
char *getfilename(char *);
void importdata(char *, int a[10][10], char operStrings[100][100]);
char *GetlastString(char *);
void change(int a[10][10], char *, int, int);
int find(int, int, char);
int isnumber(char *);
void recalculatevalues(int a[10][10], char insert[100][100]);
int main()
{
	char operStrings[100][100];
	char *str = (char *)malloc(sizeof(char));
	int a[10][10] = { 0 };
	for (int i = 0; i < 100; i++)
		operStrings[i][0] = '0';
	//printf("%d", cell1[0][0]);
	while (1)
	{
		gets(str);
		tolower(str);

		if (str[0] == 's'&&str[1] == 'e'&&str[2] == 't'&&str[3] == ' ')
		{
			//printf("hi");
			insertdata(str, a, operStrings);
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
			exportdata(str, a, operStrings);
		}
		else if (str[0] == 'i'&&str[1] == 'm'&&str[2] == 'p'&&str[3] == 'o'&&str[4] == 'r'&&str[5] == 't')
		{
			importdata(str, a, operStrings);
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
void insertdata(char *str, int a[10][10], char insert[100][100])
{

	int i, count = 0, j;
	//printf("hii");
	char *out = (char *)malloc(sizeof(char) * 10000);
	for (i = 0; str[i] != ' '; i++);
	for (j = i; str[j] == ' '; j++);
	//printf("%c %c", str[j], str[j + 1]);
	int c = str[j] - 'a';
	int row = str[j + 1] - '0' - 1;
	char *rightstr = (char *)malloc(sizeof(char) * 100);
	rightstr = GetlastString(str);
	if (isnumber(rightstr)){
		int num = getnumber(str);
		printf("num=%d ", num);
		a[row][c] = num;
		recalculatevalues(a, insert);
	}
	else
	{
		printf("hi");
		int val = row + c * 10;
		int i;
		for (i = 0; rightstr[i] != '\0'; i++)
		{
			insert[val][i] = rightstr[i];
		}
		insert[val][i] = '\0';
		puts(insert[val]);

		change(a, rightstr, row, c);
	}
}
void recalculatevalues(int a[10][10], char insert[100][100])
{
	for (int i = 0; i < 100; i++)
	{
		if (insert[i][0] != '0')
		{
			change(a, insert[i], i % 10, i / 10);
		}
	}
}
void change(int a[10][10], char *rightstr, int row, int col)
{
	int row1 = rightstr[1] - '0' - 1;
	int col1 = rightstr[0] - 'a';
	if (rightstr[2] == '\0')
	{
		a[row][col] = find(a[row1][col1], 0, '+');
		return;
	}
	char op = rightstr[2];
	int row2 = rightstr[4] - '0' - 1;
	int col2 = rightstr[3] - 'a';
	printf("%d %d %d %d", row1, col1, row2, col2);
	a[row][col] = find(a[row1][col1], a[row2][col2], op);
}
int isnumber(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (!(str[i] >= '0'&&str[i] <= '9'))
			return 0;
	}
	return 1;
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

	int i, j, count = 0;
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
void exportdata(char *str, int a[10][10], char ops[100][100])
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
			if (ops[j * 10 + i][0] != '0')
			{
				printf("wor");
				fprintf(fp, "%s", ops[j * 10 + i]);
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
void importdata(char *str, int a[10][10], char insert[100][100])
{
	char *filename = (char *)malloc(sizeof(char) * 1000);
	filename = getfilename(str);
	FILE *fp;
	fp = fopen(filename, "r");
	char c;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			int len = 0, flag = 0;
			fscanf(fp, "%d", &a[i][j]);
			//printf("%d ", a[i][j]);
			while ((c = fgetc(fp)) != ',' && c != '\n')
			{
				flag = 1;
				insert[j * 10 + i][len++] = c;
			}
			if (flag == 1){
				insert[j * 10 + i][len] = '\0';
				puts(insert[j * 10 + i]);
			}

		}
		//printf("\n");
		fgetc(fp);
	}
}
char *GetlastString(char *str)
{
	char *outputstring = (char *)malloc(sizeof(char *) * 100);
	int len = 0, i, j;
	for (j = 0; str[j] != '='; j++);
	for (i = j + 1; str[i] != '\0'; i++)
	{
		if (str[i] != ' ')
			outputstring[len++] = str[i];
	}
	outputstring[len] = '\0';
	return outputstring;
}
int find(int first, int second, char op)
{
	if (op == '+')
		return first + second;
	else if (op == '-')
		return first - second;
	else if (op == '*')
		return first*second;
	else if (op == '/')
		return first / second;
}
