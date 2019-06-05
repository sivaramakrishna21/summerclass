/*#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define size 32000
void sort(unsigned int array[size], char *);
void InsertIntoFile(unsigned int array[size], char *);
void splitIntoFiles(char *);
int mergefiles(int, char files[100][25], int, char *);
int len(int);
char *getstring(int);
int main()
{
	char *filename = (char *)malloc(sizeof(char) * 100);
	gets(filename);
	splitIntoFiles(filename);
	puts(filename);
	printf("hi");
	getchar();
}
void splitIntoFiles(char *filename)
{
	FILE *fp;
	char files[100][25];
	unsigned int array[size];
	char ch;
	puts(filename);
	int var = 0, filecount = 0;
	if (!(fp = fopen(filename, "r"))){
		printf("fj");
		return;
	}

	while (fscanf(fp, "%u%c", &array[var], &ch) != -1)
	{
		var++;
		if (var == size)
		{
			int k;
			char *s = (char *)malloc(sizeof(char));
			s = getstring(filecount + 1);
			k = strlen(s);
			
			s[k] = '.';
			s[k + 1] = 't';
			s[k + 2] = 'x';
			s[k + 3] = 't';
			s[k + 4] = '\0';
			strcpy(files[filecount], s);
			sort(array, files[filecount]);
			var = 0;
			filecount++;
		}
	}
	if (var != 0)
	{
		printf("jdfbjhdbfkjdbj");
		int k;
		char *s = (char *)malloc(sizeof(char));
		s = getstring(filecount + 1);
		k = strlen(s);

		s[k] = '.';
		s[k + 1] = 't';
		s[k + 2] = 'x';
		s[k + 3] = 't';
		s[k + 4] = '\0';
		strcpy(files[filecount], s);
		sort(array, files[filecount]);
		var = 0;
		filecount++;
	}
	mergefiles(filecount, files, 0, filename);
	fclose(fp);
}
char *getstring(int val)
{
	char *s1 = (char *)malloc(sizeof(char));
	int len = 0;
	while (val)
	{
		s1[len++] = val % 10 + '0';
		val /= 10;
	}
	s1[len] = '\0';
	return s1;
}
void sort(unsigned int array[size], char *filename)
{
	printf("sort %s", filename);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (array[i] < array[j])
			{
				unsigned int c = array[i];

				array[i] = array[j];
				array[j] = c;
			}
		}
		//printf("s=%d\n", array[i]);
	}

	InsertIntoFile(array, filename);
}
void InsertIntoFile(unsigned int array[size], char *filename)
{
	puts(filename);
	FILE *fp1;
	fp1 = fopen(filename, "w");
	for (int i = 0; i < size; i++){
		fprintf(fp1, "%u%c", array[i], '\n');
		//printf("%d", array[i]);
	}
	fclose(fp1);
}
int mergefiles(int filecount, char files[100][25], int start, char *filename)
{
	printf("%d %d", start, filecount);
	if (start + 1 >= filecount)
		return 1;
	FILE *fp1, *fp2, *fp3;
	unsigned int val, val1;
	char ch;
	fp1 = fopen(files[start], "r");
	fp2 = fopen(files[start + 1], "r");
	//printf("jdh=%d", ftell(fp1));
	int k;
	char *s = (char *)malloc(sizeof(char));
	s = getstring(filecount + 1);
	k = strlen(s);
	s[k] = '.';
	s[k + 1] = 't';
	s[k + 2] = 'x';
	s[k + 3] = 't';
	s[k + 4] = '\0';
	strcpy(files[filecount], s);
	int flag = 0;
	puts(files[filecount]);
	fp3 = fopen(files[filecount], "w");
	while (fscanf(fp2, "%u%c", &val1, &ch) != -1)
	{
		//printf("hi");
		
		if (fscanf(fp1, "%u%c", &val, &ch) != -1){
			if (val == val1)
			{
				fprintf(fp3, "%u%c", val1, ch);
				continue;
			}
			//printf("%d %d\n",ftell(fp1), ftell(fp2));
			if (val > val1)
			{
				fprintf(fp3, "%u%c", val1, ch);
				int g = len(val);
				//printf("pre=%d", ftell(fp1));
				fseek(fp1, -2 - g, SEEK_CUR);
				//printf("now=%d", ftell(fp1));
				//printf("val1=%d ", val1);
			}
			if (val1 > val)
			{
				//printf("val=%d ", val);
				//printf("pre=%d", ftell(fp2));
				int g = len(val1);
				fseek(fp2, -2 - g, SEEK_CUR);
				//printf("now=%d", ftell(fp2));
				fprintf(fp3, "%u%c", val, ch);

			}
		}
		else
		{
			fprintf(fp3, "%u%c", val1, ch);
			flag = 1;
			break;
		}

	}
	if (flag == 1)
	{
		flag = 0;
		while (fscanf(fp2, "%u%c", &val1, &ch) != -1)
		{
			//printf("hi");
			fprintf(fp3, "%u%c", val1, ch);
		}
	}

	while (fscanf(fp1, "%u%c", &val, &ch) != -1)
	{
		//printf("hi");
		fprintf(fp3, "%u%c", val, ch);
	}
	filecount++;
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	int p = mergefiles(filecount, files, start + 2, filename);
	if (p == 1)
		return 1;
}
int len(int c)
{
	int count = 0;
	while (c != 0)
	{
		count++;
		c /= 10;
	}
	return count;
}


*/






