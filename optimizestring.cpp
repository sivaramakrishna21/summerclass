#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<malloc.h>
void optimize(char *);
void numtostr(char *, int);
int main()
{
	char *s = (char *)malloc(sizeof(char) * 1000);
	int tests;
	char c;
	scanf("%d%c", &tests,&c);
	for (int i = 0; i < tests; i++)
	{
		gets(s);
		optimize(s);
	}
	getchar();
	getchar();
}
void optimize(char *str)
{
	int count=1;
	char *optstr = (char *)malloc(sizeof(char)*strlen(str));
	int len = 0;
	char prev = str[0];
	for (int i = 1; str[i-1] != '\0'; i++)
	{
		if (str[i] == prev)
			count++;
		else
		{
			
			if (count == 1)
			{
				str[len++] = prev;
				prev = str[i];
				continue;
			}
			if (count < 10)
			{
				str[len++] = prev;
				str[len++] = count + '0';
				count = 1;
				prev = str[i];
			}
			else
			{
				char *opt = (char *)malloc(sizeof(char)*10);
				numtostr(opt,count);
				str[len++] = prev;
				for (int j = 0; opt[j] != '\0'; j++)
					str[len++] = opt[j];
				count = 1;
				prev = str[i];
			}

		}
	}
	/*if (count == 1)
	{
		optstr[len++] = prev;
	}
	else if (count < 10)
	{
		optstr[len++] = prev;
		optstr[len++] = count + '0';
	}
	else
	{
		char *opt = (char *)malloc(sizeof(char) * 10);
		numtostr(opt, count);
		optstr[len++] = prev;
		for (int j = 0; opt[j] != '\0'; j++)
			optstr[len++] = opt[j];
	}*/

	str[len] = '\0';
	puts(str);
}
void numtostr(char *opt, int count)
{
	int l = 0;
	while (count != 0)
	{
		opt[l++] = count % 10+'0';
		count = count / 10;
	}
	opt[l] = '\0';
	//puts(opt);
	for (int i = 0, j = strlen(opt)-1; i <= j; i++, j--)
	{
		char p = opt[i];
		opt[i] = opt[j];
		opt[j] = p;
	}
	//puts(opt);
}












