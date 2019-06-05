#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Trie
{
	int isLeaf;
	struct Trie* character[26];
};
struct Trie* getNewTrieNode()
{
	struct Trie* node = (struct Trie*)malloc(sizeof(struct Trie));
	node->isLeaf = 0;
	for (int i = 0; i < 26; i++)
		node->character[i] = NULL;
	return node;
}
void insert(struct Trie* *head, char* str)
{
	struct Trie* curr = *head;
	int value = 0;
	while (*str != '\0')
	{
		value = *str - 'a';
		value = (value >= 0 && value <= 26) ? value : *str - 'A';
		if (curr->character[value] == NULL)
		{
			curr->character[value] = getNewTrieNode();
		}
		curr = curr->character[value];
		str++;
	}
	curr->isLeaf = 1;
}
int check(struct Trie *head, char *str,int array[], int count)
{
	int i = 0;
	for (i = 0; i < 26 && array[i] == 0; i++);
	if (i == 26 && head->isLeaf)
	{
		str[count] = '\0';
		
		printf("%s\n", str);
		return 1;
	}
	for (int j = 0; j < 26; j++)
	{
		if (array[j] && head->character[j] != NULL)
		{
			
			array[j]--;
			str[count] = j + 'a';
			if (check(head->character[j],str,array, count + 1));
				array[j]++;
		}
	}
	return 0;
}
void getallanagrams(struct Trie *head)
{
	char string[100];
	gets(string);
	int count = 0;
	char str[100];
	int array[26] = { 0 };
	for (int i = 0; string[i] != '\0'; i++)
	{
		array[string[i] - 'a']++;
	}
	
	for (int i = 0; i < 26; i++)
	{
		if (array[i]!=0)
		{
	
			array[i]--;
			if (head->character[i])
			{
				str[0] = i + 'a';
				if (check(head->character[i],str,array, count + 1));
			}
			array[i]++;
		}
	}
}
/*int main()
{
	FILE *fp;
	struct Trie *head = getNewTrieNode();
	char filename[100], s[100];
	gets(filename);
	fopen_s(&fp, filename, "r");
	while (fscanf(fp, "%s", &s) != EOF)
	{
		
		insert(&head, s);
	}
	fclose(fp);
	getallanagrams(head);
}*/