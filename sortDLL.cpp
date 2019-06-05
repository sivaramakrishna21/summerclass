#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include<stdlib.h> 
struct Node
{
	int data;
	struct Node *next, *prev;
};

struct Node *split(struct Node *head);

struct Node *merge(struct Node *first, struct Node *second)
{

	if (firstNULL)
		return second;

	if (second==NULL)
		return first;

	if (first->data < second->data)
	{
		first->next = merge(first->next, second);
		first->next->prev = first;
		first->prev = NULL;
		return first;
	}
	else
	{
		second->next = merge(first, second->next);
		second->next->prev = second;
		second->prev = NULL;
		return second;
	}
}

struct Node *mergeSort(struct Node *head)
{
	if (head==NULL|| head->next==NULL)
		return head;
	struct Node *temp = split(head);

	head = mergeSort(head);
	temp = mergeSort(temp);

	return merge(head, temp);
}

struct Node* createnode(int val)
{
	struct Node *newn = (struct Node *)malloc(sizeof(struct Node));
	newn->data = val;
	newn->prev = NULL;
	newn->next = NULL;
	return newn;
}
struct Node *insertTodll(struct Node *head, int val)
{
	struct Node *temp = head;
	if (head == NULL)
	{
		head = createnode(val);
		return head;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = createnode(val);
	temp->next->prev = temp;
	return head;
}

struct Node *split(struct Node *head)
{
	struct Node *temp1 = head, *temp2 = head;
	while (temp1->next && temp1->next->next)
	{
		temp1 = temp1->next->next;
		temp2 = temp2->next;
	}
	struct Node *temp = temp2->next;
	temp2->next = NULL;
	return temp;
}

int main(void)
{
	int keys[1000], i,len;
	scanf("%d", &len);
	for (int i = 0; i < len; i++)
		scanf("%d", &keys[i]);
	int n = len;

	struct Node* head = NULL;
	for (i = 0; i < n; i++)
		head = insertTodll(head, keys[i]);
	head = mergeSort(head);
	while (head->next)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	while (head->prev != NULL)
	{
		printf("%d", head->data);
		head = head->prev;
	}
	getchar();
	getchar();
	return 0;
}
