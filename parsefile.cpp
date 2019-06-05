#define _CRT_SECURE_NO_WARNINGS
#define _CRT_STDC_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include "structures.h"
#include<malloc.h>

struct symboltable
{
	int address;
	char name;
	int size;
};
struct intermediate
{
	int opcode;
	int parameters;
	int param[10];
};
struct lable{
	int address;
	char *blockname;
};
void addprintdata(char *c, int imdcount, struct intermediate im[20], struct symboltable st[10], int stcount)
{
	im[imdcount].parameters = 1;
	im[imdcount].opcode = 13;
	for (int i = 0; i < stcount; i++)
	{
		if (st[i].name == c[0])
		{
			im[imdcount].param[0] = st[i].address;
		}
	}
}
void addfun(char *c, int imdcount, struct intermediate im[20])
{
	printf("hie");
	im[imdcount].parameters = 3;
	im[imdcount].opcode = 3;
	im[imdcount].param[0] = c[0] - 'A';
	im[imdcount].param[1] = c[3] - 'A';
	im[imdcount].param[2] = c[6] - 'A';
}

void registertomemory(int pos,char *c, int imdcount, char instructions[22][10], struct symboltable st[10], struct intermediate im[20], int stcount)
{
	im[imdcount].parameters = 2;
	im[imdcount].opcode = 1;
	int len = 0;
	
	for (int i = 0; i < stcount; i++)
	{
		//printf("%d %c %c\n",stcount, st[i].name, c[0]);
		if (st[i].name == c[0]){
			im[imdcount].param[len++] =st[i].address+pos-1;
			break;
		}
		
	}
	im[imdcount].param[1] = c[strlen(c)-2] - 'A';
}
void memorytoregister(int pos,char *c, int imdcount, char instructions[22][10], struct symboltable st[10], struct intermediate im[20], int stcount)
{
	im[imdcount].parameters = 2;
	im[imdcount].opcode = 2;
	int len = 0;
	im[imdcount].param[0] = c[0] - 'A';
	for (int i = 0; i < stcount; i++)
	{
		if (st[i].name == c[3])
			im[imdcount].param[1] = st[i].address+pos-1;
	}
}
void placeinsymboltable(struct symboltable st[10],int stcount, int arraysize, char inst)
{
	if (stcount == 0)
	{
		st[stcount].address = 0;
		st[stcount].size = arraysize;
		st[stcount].name = inst;

	}
	else
	{
		st[stcount].address = st[stcount - 1].size + st[stcount - 1].address;
		st[stcount].size = arraysize;
		st[stcount].name = inst;

	}
}
void addtoimd(struct intermediate im[20], char *c, int imdcount,char instructions[23][10])
{
	im[imdcount].opcode = 14;
	im[imdcount].parameters = 1;
	im[imdcount].param[0] = c[0] - 'A';
}
int getmemorycount(char *c)
{
	if (c[1] == '\n' || c[1] == '\0')
		return 1;
	char *bytes = (char *)malloc(sizeof(char) * 10);
	bytes = strchr(c, '[') + 1;
	int value = 0;
	for (int i = 0; bytes[i] != '\0'&&bytes[i] >= '0'&&bytes[i] <= '9'; i++)
	{
		value = value * 10 + bytes[i] - '0';
	}
	return value;
}
void addchar(char *arr, int bytes, char c)
{
	int i;
	for (i = strlen(arr); i < bytes + strlen(arr); i++)
		arr[i] = c;
	arr[i] = '\0';
}
void replace(int position, struct intermediate im[20],int imdcount)
{
	printf("pos=%d", position);
	im[position-1].param[0] = imdcount;

}
void  addIfToTable(int stack[10], FILE *fp, int top, int count, struct intermediate im[20], char instructions[23][10])
{
	im[count].parameters = 4;
	im[count].opcode = 7;
	stack[++top] = count+1;
	char *ch = (char *)malloc(sizeof(char));
	fscanf(fp, "%s", ch);
	im[count].param[0] = ch[0] - 'A';
	fscanf(fp, "%s", ch);
	for (int i = 0; i < 23; i++)
	{
		if (strcmp(ch, instructions[i]) == 0){
			im[count].param[2] = i + 1;
			break;
		}
	}
	fscanf(fp, "%s", ch);
	printf("hiiiiii");
	puts(ch);
	im[count].param[1] = ch[0] - 'A';
	fscanf(fp, "%s", ch);
	im[count].param[3] = -1;
}
void addElseToTable(struct intermediate im[20], int imdcount)
{
	im[imdcount].parameters = 1;
	im[imdcount].opcode = 6;
	im[imdcount].param[0] = -1;
}
void parsefile()
{
	FILE *fp;
	char ch;
	int stack[10], top = -1,lablecount=0;
	char *inst = (char *)malloc(sizeof(char) * 20);
	char *c = (char *)malloc(sizeof(char) * 5);
	struct lable lable1[10];
	char instructions[22][10] = { "MOV", "MOV", "ADD", "SUB", "MUL", "JMP", "IF", "EQ", "LT", "GT", "LTEQ", "GTEQ", "PRINT", "READ", "AX", "BX", "CX", "DX", "EX", "FX", "GX", "HX" };
	fp = fopen("input.txt", "r");
	struct symboltable st[10];
	struct intermediate im[20];
	int imdcount=0;
	int stcount = 0;
	while (fscanf(fp, "%s%c", inst,&ch) != -1)
	{
		//printf("loop");
		puts(inst);
		if (strcmp(inst, "DATA") == 0)
		{

			fscanf(fp, "%s", c);
			int arraysize = getmemorycount(c);
			printf("arr=%d", arraysize);
			placeinsymboltable(st,stcount, arraysize,c[0]);
			printf("%d ", st[stcount].address);
			stcount++;
		}
		else if (strcmp(inst, "CONST") == 0)
		{
			fscanf(fp, "%s", c);
			placeinsymboltable(st,stcount, 0, c[0]);
			fgets(c, 100, fp);

			stcount++;
		}
		else if (strcmp(inst, "START:") == 0){
			for (int i = 0; i < stcount; i++)
			{
				printf("%d %d %c\n", st[i].address, st[i].size, st[i].name);
			}
		}
		else if (strcmp(inst, "READ") == 0)
		{
			fscanf(fp, "%s", c);
			addtoimd(im, c, imdcount,instructions);
			imdcount++;
		}
		else if (strcmp(inst, "MOV") == 0)
		{
			fscanf(fp, "%s", c);

			int len;
			puts(c);
			char *temp = (char *)malloc(sizeof(char) * 100);
			strcpy(temp, c);
			char *lastword = (char *)malloc(sizeof(char));
			if (strchr(c, '[') != NULL)
			{
				lastword = strchr(c, '[')+1;
				puts(lastword);
				for (int i = strlen(lastword) - 1, j = 0; i >= j; i--, j++)
				{
					char c = lastword[i];
					lastword[i] = lastword[j];
					lastword[j] = c;
				}
				lastword = strchr(lastword, ']') + 1;
				sscanf(lastword, "%d", &len);
				len += 1;
			}
			else
			{
				len = 1;
			}
			printf("mov=%s", c);
			puts(c);
			
			lastword = strchr(c, ',') + 1;
			strcpy(c, temp);
			if (lastword[1]== 'X')
			{
				printf("hii");
				puts(c);
				registertomemory(len,c, imdcount, instructions, st, im,stcount);
				imdcount++;
			}
			else if(c[2] == ',')
			{
				memorytoregister(len,c, imdcount, instructions, st, im, stcount);
				imdcount++;
			}
	
		}
		else if (strcmp(inst, "ADD")==0)
		{
			//printf(":in");
			fscanf(fp, "%s", c);
			puts(c);
			addfun(c, imdcount, im);
			imdcount++;
		}
		else if (strcmp(inst, "PRINT") == 0)
		{
			fscanf(fp, "%s", c);
			addprintdata(c, imdcount, im,st,stcount);
			imdcount++;
		}
		else if (strcmp(inst, "IF") == 0)
		{
			addIfToTable(stack, fp, top,imdcount,im,instructions);
			imdcount++;
			//lablecount++;
			top++;
		}
		else if (strcmp(inst, "ELSE") == 0)
		{
			printf("lable=%d", lablecount);
			
			puts(inst);
			lable1[lablecount].blockname = (char *)malloc(sizeof(char)*strlen(inst));
			strcpy(lable1[lablecount].blockname, inst);
			stack[++top] = imdcount+1;
			printf("%d %d %d", stack[top], stack[top - 1],lablecount);
			addElseToTable(im, imdcount);
			
			imdcount++;
			lable1[lablecount].address = imdcount + 2;
			lablecount++;
		}
		else if (strcmp(inst, "ENDIF") == 0)
		{
			im[imdcount].opcode = 6;
			im[imdcount].parameters = 1;
			
			lable1[lablecount].blockname = (char *)malloc(sizeof(char)*strlen(inst));
			strcpy(lable1[lablecount].blockname, inst);
			lable1[lablecount].address = imdcount+2;
			printf("sss=%s %d", lable1[lablecount - 1].blockname,stack[top]);
			if (strcmp(lable1[lablecount - 1].blockname, "ELSE") == 0)
			{
				im[imdcount].param[0] = stack[top - 1];
				//replace(stack[top], im, imdcount);
				im[stack[top]-1].param[0] = imdcount + 1;
				top--;
				printf("yoo=%d", stack[top]);
				im[stack[top]-1].param[3] = stack[top + 1] + 1;
				top--;
			}
			else
			{
				im[imdcount].param[0] = stack[top];
				im[stack[top]].param[3] = stack[imdcount];
				top--;
			}

			imdcount++;
		}

		
		
	}
	
	printf("out=%s\n", inst);
	for (int i = 0; i < imdcount; i++)
	{
		printf("\n%d ", im[i].opcode);
		for (int j = 0; j < im[i].parameters; j++)
			printf("%d ", im[i].param[j]);

		
	}
	printf("\n");
	for (int i = 0; i < stcount; i++)
		printf("%d st=%d ", stcount, st[i].address);
	fclose(fp);
	getchar();
	getchar();
}
