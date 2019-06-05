#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<malloc.h>
void writezeros(char *);
void tolower(char *);
void insertdata(char *, struct cell **);
void getdata(char *,struct cell**);
int getnumber(char *);
void exportdata(char *, struct cell **, char *name);
void printdata(struct cell **);
char *getfilename(char *);
void importdata(char *, struct cell **, char *);
char *GetlastString(char *);
void change(int a[10][10], char *, int, int);
int find(int, int, char);
int isnumber(char *);
int recalculatevalues(int a[10][10], char insert[100][100], int);
int iscycle1(int a[10][10], char insert[100][100], int);
int iscycle(int a[10][10], char insert[100][100], int, int);
int preceed(char);
int cal(int, int, char);
int getvalue(char);
int eval(char *, char *, int *,struct cell **);
struct cell{
	int a;
	char *insert;
	
};
int main()
{
	enum datatype{in,cha};
	struct cell **cell1 = (struct cell**)malloc(sizeof(struct cell *)*10);
	for (int i = 0; i < 10; i++)
		cell1[i] = (struct cell*)malloc(sizeof(struct cell) * 10);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++){
			
			cell1[i][j].insert = NULL;
			cell1[i][j].a = 0;
		}
	}
	char operStrings[100][100];
	char *str = (char *)malloc(sizeof(char));
	int a[10][10] = { 0 };
	char *name = (char *)malloc(sizeof(char) * 100);
	name[0] = '\0';
	//for (int i = 0; i < 100; i++)
		//operStrings[i][0] = '0';
	//printf("%d", cell1[0][0]);

	while (1)
	{
		printf("$");
		gets(str);
		if (strcmp(str, "excel.exe") == 0)
			break;
	}
	while (1)
	{
		printf(">");
		gets(str);
		tolower(str);
		if (str[0] == 's'&&str[1] == 'e'&&str[2] == 't'&&str[3] == ' ')
		{
			
			//printf("hi");
			insertdata(str, cell1);
		}
		else if (str[0] == 'g'&&str[1] == 'e'&&str[2] == 't'&&str[3] == ' ')
		{
			getdata(str, cell1);
		}
		else if (strcmp(str, "print") == 0)
		{
			printdata(cell1);
		}
		else if (str[0] == 'e'&&str[1] == 'x'&&str[2] == 'p'&&str[3] == 'o'&&str[4] == 'r'&&str[5] == 't')
		{
			exportdata(str,cell1, name);
		}
		else if (str[0] == 'i'&&str[1] == 'm'&&str[2] == 'p'&&str[3] == 'o'&&str[4] == 'r'&&str[5] == 't')
		{
			importdata(str,cell1, name);
		}
		else if (str[0] == 'e'&&str[1] == 'x'&&str[2] == 'i'&&str[3] == 't')
		{
			break;
		}
		else  if (str[0] == 's'&&str[1] == 'a'&&str[2] == 'v'&&str[3] == 'e')
		{
			puts(name);
			if (name[0] != '\0')
			{
				int i;
				char s[100] = "export ";
				for (i = 0; name[i] != '\0'; i++)
				{
					s[7 + i] = name[i];
				}
				s[7 + i] = '\0';
				puts(s);
				exportdata(s, cell1, name);
			}
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
void insertdata(char *str, struct cell **cell1)
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
	puts(rightstr);
	if (isnumber(rightstr)){
		int num = getnumber(str);
		//printf("num=%d ", num);
		//a[row][c] = num;
		
		cell1[row][c].a = num;
		cell1[row][c].insert = NULL;
		char *exparray = (char *)malloc(sizeof(char) * 1000);
		int *operandsarray = (int *)malloc(sizeof(int) * 1000);
		for (int i = 0; i < 100; i++)
			operandsarray[i] = 0;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (cell1[i][j].insert != NULL)
				{
					int p = eval(cell1[i][j].insert, exparray, operandsarray, cell1);
					//int p = eval(insert[i], exparray, operandsarray, a, insert);
					cell1[i][j].a = p;
				}
			}
			
		}
	}
	else
	{
		printf("hi");
		int val = row + c * 10;
		int i;
		puts(rightstr);
		cell1[row][c].insert = (char *)malloc(sizeof(char) * 100);
		for (i = 0; rightstr[i] != '\0'; i++)
		{
			cell1[row][c].insert[i] = rightstr[i];
			
		}
		cell1[row][c].insert[i] = '\0';
		puts(cell1[row][c].insert);
		//int *checkcyclearray = (int *)malloc(sizeof(int));
		//int cyc = iscycle1(a, insert, val);
		int cyc = 0;
		if (cyc == 1){
			printf("hii");
		}
		else
		{
			//printf("valid");
			//change(a, rightstr, row, c);

			char *exparray = (char *)malloc(sizeof(char) * 1000);
			int *operandsarray = (int *)malloc(sizeof(int) * 1000);
			for (int i = 0; i < 100; i++)
				operandsarray[i] = 0;
			cell1[row][c].a = eval(rightstr, exparray, operandsarray,cell1);
			//printf("%d",ce)
			printf("oy");
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					if (cell1[i][j].insert != NULL)
					{
						int p = eval(cell1[i][j].insert, exparray, operandsarray, cell1);
						//int p = eval(insert[i], exparray, operandsarray, a, insert);
						cell1[i][j].a = p;
					}
				}
				
			}
		}
	}
}
int eval(char *evalstring, char *exparray, int *operandarray,struct cell **cell1)
{
	//printf("c=%d", a[0][0]);
	int expf = 0, oprf = 0, row, col;
	char c[4];
	c[0] = '\0';
	for (int i = 0; evalstring[i] != '\0'; i++)
	{
		switch (evalstring[i])
		{
		case '(':exparray[expf++] = '(';
			break;
		case ')':
			while (exparray[--expf] != '(')
			{

				operandarray[oprf - 2] = cal(operandarray[oprf - 1], operandarray[oprf - 2], exparray[expf]);

				oprf -= 1;

			}

			break;
		case '+':
		case '-':
		case '*':
		case '/':
			while (preceed(exparray[expf - 1]) >= preceed(evalstring[i]))
			{
				operandarray[oprf - 2] = cal(operandarray[oprf - 1], operandarray[oprf - 2], exparray[--expf]);
				oprf -= 1;
			}
			exparray[expf++] = evalstring[i];
			break;
		default:
			printf("%c", evalstring[i]);
			if (c[0] == '\0'&&evalstring[i] >= '0'&&evalstring[i] <= '9'){
				int num = 0;
				for (int j = i; evalstring[j] >= '0'&&evalstring[i] <= '9'; j++)
				{
					num = num * 10 + (evalstring[j] - '0');
					printf("num=  %d", num);
					i++;
				}
				i--;
				operandarray[oprf++] = num;
				//printf("\n111");
			}
			else if (c[0] == '\0'){
				c[0] = evalstring[i];
				c[1] = '\0';
				//printf("\n11111");
			}
			else if (c[0] != '\0'){
				//printf("\n%c",evalstring[i]);

				c[1] = evalstring[i];
				c[2] = '\0';
				//printf("\nstr=%c", c[0]);
				col = c[0] - 'a';
				row = c[1] - '0' - 1;
				//printf("%d %d\n", col, row);
				//puts(c);
				
				if (cell1[row][col].insert != NULL){
					printf("dhb");
					operandarray[oprf++] = eval(cell1[row][col].insert, exparray, operandarray,cell1);
					printf("val=%d ", operandarray[oprf - 1]);
					c[0] = '\0';
				}
				else
				{
					printf("%d", cell1[row][col].a);
					operandarray[oprf++] = cell1[row][col].a;
					c[0] = '\0';
				}

			}

			//printf("%d ", operandarray[oprf - 1]);
			break;
		}


	}
	//printf("\n%d %d %c\n", operandarray[0],operandarray[1],exparray[expf-1]);
	while (expf != 0)
	{
		//printf("hi");
		operandarray[oprf - 2] = cal(operandarray[oprf - 1], operandarray[oprf - 2], exparray[--expf]);
		oprf -= 1;
	}
	printf("\nsol=%d ", operandarray[0]);
	return operandarray[0];
}
/*int iscycle(int a[10][10], char insert[100][100], int i, int p)
{

	int  j, sum = 0, sum1 = 0;
	char c;
	if (p == i)
		return 1;
	if (insert[i][0] == '0')
		return 0;
	if (insert[i][0] >= 'a'&&insert[i][0] <= 'z')
	{
		int c = insert[i][0] - 'a';
		int row = insert[i][1] - '0' - 1;
		j = 2;
		sum = iscycle(a, insert, (c * 10) + row, p);
		if (sum == 1)
			return 1;
	}

	if (insert[i][j] != '\0')
	{
		c = insert[i][j++];
		if (!(insert[i][j] >= '0'&&insert[i][j] <= '9'))
		{

			int c = insert[i][j++] - 'a';
			int row = insert[i][j++] - '0' - 1;
			sum1 = iscycle(a, insert, (c * 10) + row, p);
			if (sum1 == 1)
				return 1;
		}
	}

	if (sum == 1 || sum1 == 1)
		return 1;
	return 0;
}*/
/*int recalculatevalues(int a[10][10], char insert[100][100], int i)
{
	int sum = 0, j, sum1 = 0;
	char c;
	if (insert[i][0] == '0')
		return a[i % 10][i / 10];
	if (insert[i][0] >= 'a'&&insert[i][0] <= 'z')
	{
		int c = insert[i][0] - 'a';
		int row = insert[i][1] - '0' - 1;
		j = 2;
		sum = recalculatevalues(a, insert, (c * 10) + row);
	}
	else if (insert[i][0] >= '0'&&insert[i][0] <= '9')
	{
		sum = insert[i][0] - '0';
		j = 1;
	}
	if (insert[i][j] != '\0')
	{
		c = insert[i][j++];
		if (insert[i][j] >= '0'&&insert[i][j] <= '9')
		{
			sum1 = insert[i][j] - '0';
		}
		else{
			int c = insert[i][j++] - 'a';
			int row = insert[i][j++] - '0' - 1;
			sum1 = recalculatevalues(a, insert, (c * 10) + row);
		}
	}
	else
	{
		sum1 = 0;
		c = '+';
	}
	return find(sum, sum1, c);

}*/
/*void change(int a[10][10], char *rightstr, int row, int col)
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
	//printf("%d %d %d %d", row1, col1, row2, col2);
	a[row][col] = find(a[row1][col1], a[row2][col2], op);
}*/
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
void getdata(char *str, struct cell **cell1)
{

	int i, j, count = 0;
	//char *out = (char *)malloc(sizeof(char) * 10000);

	for (i = 0; str[i] != ' '; i++);
	for (j = i; str[j] == ' '; j++);
	int c = str[j] - 'a';
	int row = str[j + 1] - '0' - 1;
	printf("%d\n",cell1[row][c].a);

}
void printdata(struct cell **cell1)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			printf("%d ", cell1[i][j].a);
		printf("\n");
	}

}
void exportdata(char *str, struct cell **cell1, char *name)
{
	char *filename = (char *)malloc(sizeof(char) * 1000);
	filename = getfilename(str);
	int len = 0;
	for (int i = 0; filename[i] != '\0'; i++)
		name[len++] = filename[i];
	name[len] = '\0';
	FILE *fp;
	fp = fopen(filename, "w");
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			fprintf(fp, "%d", cell1[i][j].a);
			if (cell1[i][j].insert!= NULL)
			{
				//printf("wor");
				fprintf(fp, "%s", cell1[i][j].insert);
				
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
	//puts(filename);
	return filename;
}
void importdata(char *str, struct cell **cell1, char *name)
{
	char *filename = (char *)malloc(sizeof(char) * 1000);
	filename = getfilename(str);
	int w;
	for (w = 0; filename[w] != '\0'; w++)
		name[w] = filename[w];
	name[w] = '\0';
	//puts(name);
	FILE *fp;
	fp = fopen(filename, "r");
	char c;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			int len = 0, flag = 0;
			fscanf(fp, "%d", &cell1[i][j].a);
			//printf("%d ", a[i][j]);
			cell1[i][j].insert = (char *)malloc(sizeof(char) * 100);
			while ((c = fgetc(fp)) != ',' && c != '\n')
			{
				flag = 1;
				cell1[i][j].insert[len++] = c;
				//insert[j * 10 + i][len++] = c;
			}
			if (flag == 1){
				cell1[i][j].insert[len++] = '\0';
				puts(cell1[i][j].insert);
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



int cal(int a, int b, char c)
{
	if (c == '+')
		return b + a;
	else if (c == '-')
		return b - a;
	else if (c == '*')
		return b*a;
	else if (c == '/')
		return b / a;

}
int preceed(char c)
{
	if (c == '^')
		return 6;
	else if (c == '*' || c == '*')
		return 5;
	else if (c == '+' || c == '-')
		return 4;
	else if (c == '(')
		return 0;
}
int getvalue(char c)
{
	if (c >= '0'&&c <= '9')
		return c - '0';
	return c - 'a';
}
/*int iscycle1(int a[10][10], char insert[100][100], int i)
{
	int j, sum = 0, sum1 = 0;
	if (insert[i][0] == '0')
		return 0;
	if (insert[i][0] >= 'a'&&insert[i][0] <= 'z')
	{
		int c = insert[i][0] - 'a';
		int row = insert[i][1] - '0' - 1;
		j = 2;
		sum = iscycle(a, insert, (c * 10) + row, i);
	}

	if (insert[i][j] != '\0')
	{
		int c = insert[i][j++];
		if (insert[i][j] >= '0'&&insert[i][j] <= '9')
		{
			sum1 = insert[i][j] - '0';
		}
		else{
			int c = insert[i][j++] - 'a';
			int row = insert[i][j++] - '0' - 1;
			sum1 = iscycle(a, insert, (c * 10) + row, i);
		}
	}

	if (sum1 == 0 && sum == 0)
		return 0;
	return 1;
	}*/
