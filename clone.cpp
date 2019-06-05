#define _CRT_SECURE_NO_WARNINGS
#include<malloc.h>
#include<stdio.h>
#include<map>
#include<iostream>
struct node *clone(struct node *);
struct node{
	int data;
	struct node *next;
	struct node *random;
}*head;

struct node *newnode(int c)
{
	struct node *newn = (struct node *)malloc(sizeof(struct node));
	newn->data = c;
	newn->next = NULL;
	newn->random = NULL;
	return newn;
}
struct node *insertatend(int p, struct node *head)
{
	struct node *temp = head;
	if (temp == NULL)
	{
		temp = newnode(p);
		return temp;
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = newnode(p);
	return head;
}
struct node *clone1(struct node *head)
{
	
	std::map<struct node *, struct node *> hashtable;
	struct node *head1 = newnode(head->data);
	struct node *temp1= head1, *temp = head;
	hashtable[temp] = temp1;
	temp = temp->next;
	while (temp != NULL)
	{
		struct node *newn = newnode(temp->data);
		temp1->next = newn;
		temp1 = temp1->next;
		hashtable[temp] = temp1;
		temp = temp->next;
	}
	temp1 = head1;
	temp = head;
	while (temp != NULL)
	{
		if (temp->random!=NULL)
		{
			temp1->random = hashtable[temp->random];
		}
		temp1 = temp1->next;
		temp = temp->next;

	}

	return head1;
}
int main()
{
	int n, value, count = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &value);
		head = insertatend(value, head);
	}
	struct  node *tem = head;
	tem->random = head->next->next;
	tem = tem->next;
	tem->random = tem->next->next;
	tem = tem->next;
	tem->random = head;
	tem = tem->next;
	tem->random = head->next;
	tem = tem->next;
	tem->random = head->next->next;
	
	head = clone1(head);
	while (head != NULL)
	{
		printf("%d %d\n", head->data, head->random->data);
		head = head->next;
	}
	getchar();
	getchar();
}
