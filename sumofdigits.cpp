#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<malloc.h>

struct node{
	int val;
	struct node* next;
};
struct node * createNode(int n1) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->val = n1;
	newNode->next = NULL;
	return newNode;
}

void insertAtEnd(struct node **head, int p){
	struct node *temp = *head;
	if (*head == NULL){
		(*head) = createNode(p);
		(*head)->next = NULL;
	}
	else{
		while (temp->next != NULL){
			temp = temp->next;
		}
		temp->next = createNode(p);
		temp->next->next = NULL;
	}
}

void insertAtBeg(struct node **head, int p){
	if (*head == NULL){
		(*head) = createNode(p);
		(*head)->next = NULL;
	}
	else{
		struct node *newNode = createNode(p);
		newNode->next = (*head);
		(*head) = newNode;
	}
}

int sumDigits(struct node *head1, struct node *head2, int c, int k, struct node **head3){
	if (head1 == NULL || head2 == NULL)
		return 0;
	int carry = 0;
	if (c < k){
		carry = sumDigits(head1->next, head2, c + 1, k, head3);
		insertAtBeg(head3, (carry + head1->val) % 10);
		return (carry + head1->val) / 10;
	}
	carry = sumDigits(head1->next, head2->next, c + 1, k, head3);
	insertAtBeg(head3, ((carry + head1->val + head2->val) % 10));
	return (carry + head1->val + head2->val) / 10;
}

int main(){
	char* num1 = (char*)malloc(sizeof(char) * 100);
	char* num2 = (char*)malloc(sizeof(char) * 100);
	printf("\n enter first number \n");
	gets(num1);
	printf("\n enter second number \n");
	gets(num2);
	struct node *head1 = NULL;
	struct node *head2 = NULL;
	struct node *head3 = NULL;
	//printf("%s %s", num1, num2);
	for (int i = 0; num1[i] != '\0'; i++)
		insertAtEnd(&head1, num1[i] - '0');
	for (int i = 0; num2[i] != '\0'; i++)
		insertAtEnd(&head2, num2[i] - '0');
	if (strlen(num2) > strlen(num1)){
		int carry = sumDigits(head2, head1, 0, strlen(num2) - strlen(num1), &head3);
		if (carry > 0)
			insertAtBeg(&head3, carry);
	}
	else{
		int carry = sumDigits(head1, head2, 0, strlen(num1) - strlen(num2), &head3);
		if (carry > 0)
			insertAtBeg(&head3, carry);
	}
	struct node *temp = head3;
	printf("\n\n Sum of two numbers is = ");
	while (temp != NULL){
		printf("%d", temp->val);
		temp = temp->next;
	}
	getchar();
	getchar();
	return 0;
}