/*#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define PAGESIZE 32	
int insertdataintostruct(int);
void inserttofile(char *, int);
void readdata(int);
int insertintoblock(int);
char *getdata(int);
#pragma pack(1)
struct nonleaf{
	char pagetype;
	char unused[3];
	int data[3];
	int child[4];

};
struct pageinfo{
	char pagebuf[PAGESIZE];
	int used;
	int pageid;
};
struct leaf{
	char pagetype;
	char unused[4];
	int sid[3];
	char name[3][5];
};
void inserttofile(char *data, int blocknumber)
{
	FILE *fp;
	fp = fopen("siva.txt", "rb+");
	//puts(data);
	fseek(fp, blocknumber*PAGESIZE, SEEK_SET);
	fwrite(data, sizeof(char)*PAGESIZE, 1, fp);
	fclose(fp);
}
char *getdata(int blocknumber)
{
	FILE *fp;
	char *data = (char *)malloc(sizeof(char)*PAGESIZE);
	fp = fopen("siva.txt", "rb");
	fseek(fp, blocknumber*PAGESIZE, SEEK_SET);
	fread(data, PAGESIZE, 1, fp);
	fclose(fp);
	return data;

}
int main()
{
	//int blocknumber = 0;
	//insertdataintostruct();
	int blocknumber = 0;
	while (1)
	{
		char *command = (char *)malloc(sizeof(char) * 100);
		gets(command);
		if (strcmp(command, "WRITELEAF") == 0)
		{
			blocknumber = insertdataintostruct(blocknumber);
		}
		else if (strcmp(command, "WRITENONLEAF") == 0)
		{

			blocknumber = insertintoblock(blocknumber);
		}
		else
		{
			printf("%d", blocknumber);
			readdata(5);
		}
	}
	getchar();
	getchar();
}
int insertdataintostruct(int blocknumber)
{
	struct leaf nl1[4];
	struct leaf nl2;
	char c;
	for (int i = 0; i < 4; i++){
		printf("enter data");
		nl1[i].pagetype = '1';
		gets(nl1[i].name[0]);
		gets(nl1[i].name[1]);
		gets(nl1[i].name[2]);

		scanf("%d%d%d%c", &nl1[i].sid[0], &nl1[i].sid[1], &nl1[i].sid[2], &c);
		printf("%d\n", nl1[i].sid[0]);
		puts(nl1[i].name[0]);

		char *ch = (char *)malloc(sizeof(char)*PAGESIZE);
		memcpy(ch, &nl1[i], sizeof(nl1[i]));
		inserttofile(ch, blocknumber);
		blocknumber++;
	}
	return blocknumber;
}
void readdata(int blocknumber)
{
	struct leaf nl2;
	for (int i = 0; i < blocknumber; i++)
	{
		char *ch = (char *)malloc(sizeof(char)*PAGESIZE);
		ch = getdata(i);
		memcpy(&nl2, ch, sizeof(char)*PAGESIZE);
		puts(nl2.name[0]);
	}
}
int insertintoblock(int blocknumber)
{
	struct nonleaf nl1;
	struct leaf l1;
	int len = 0;
	char *ch = (char *)malloc(sizeof(char) * 100);
	//scanf("%d%d%d", nl1.data[0], nl1.data[1], nl1.data[2]);
	nl1.child[len] = blocknumber;
	//memcpy(&l1, ch, sizeof(char)*PAGESIZE);
	for (int j = 1; j < blocknumber; j++)
	{

		ch = getdata(j);
		memcpy(&l1, ch, sizeof(char)*PAGESIZE);
		nl1.data[len++] = l1.sid[0];
		printf("%d%d", nl1.data[len - 1], j);
		nl1.data[len] = j;
	}

	memcpy(ch, &nl1, sizeof(nl1));
	inserttofile(ch, blocknumber);

	blocknumber++;
	return blocknumber;
}*/