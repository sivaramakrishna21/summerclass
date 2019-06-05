#define _CRT_SECURE_NO_WARNINGS
#include<malloc.h>
#include<stdio.h>
struct node{
	int data;
	struct node *next;
}*head;

struct node *newnode(int c)
{
	struct node *newn = (struct node *)malloc(sizeof(struct node));
	newn->data = c;
	newn->next = NULL;
	return newn;
}
struct node *reverse(struct node *head)
{
	struct node *prev = NULL, *next1 = head->next, *present = head;
	
	
	while (present != NULL)
	{
		present->next = prev;
		prev = present;
		present = next1;
		if (next1!=NULL)
		next1 = next1->next;
	}
	head = prev;
	
	head = prev;
	return head;
}
struct node *insertatend(int p,struct node *head)
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
int main()
{
	int n, k,value,count=0;
	
	scanf("%d%d", &n, &k);
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &value);
		head=insertatend(value,head);
	}
	struct node *temp = head, *head1, *head2 = NULL, *head3 = NULL, *head4 = head;
	if (k == n)
	{
		//printf("%d", head->next->next->data);
		head=reverse(head);
	}
	
	while (temp != NULL)
	{
		count++;
		if (count == k)
		{
			//printf("jhf");
			head2 = temp->next;
			temp->next = NULL;
			head1=reverse(head4);
			if (head3 == NULL){
				head = head1;
				while (head1->next != NULL)
					head1 = head1->next;
				head3 = head1;
			}
			else
			{
				head3->next = head1;
				while (head1->next != NULL)
					head1 = head1->next;
				head3 = head1;
			}
			
			//printf("\n");
			count = 0;
			head4 = head2;
			temp = head2;
			continue;
		}
		//printf("%d", temp->data);
		temp = temp->next;
	}
	
		
	while (head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	if (count > 0)
	{
		while (head4 != NULL)
		{
			printf("%d ", head4->data);
			head4 = head4->next;
		}
	}
	getchar();
	getchar();
}
