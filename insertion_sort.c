#include<stdio.h>
#include<stdlib.h>

#define LIST_SIZE 5

struct node
{
	int data;
	struct node *next;
	struct node *head;
};

void print_list(struct node *ptr )
{
	while(ptr != NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

void sort_insert(struct node **head, struct node *new_node) 
{ 
	struct node *current; 
	if (*head == NULL || (*head)->data >= new_node->data) 
	{ 
		new_node->next = *head; 
		*head = new_node; 
	} 
	else
	{ 
		current = *head; 
		while (current->next!=NULL && current->next->data < new_node->data) 
		{ 
			current = current->next; 
		} 
		new_node->next = current->next; 
		current->next = new_node; 
	} 
} 

void insertion_sort(struct node *head) 
{ 
	struct node *sorted = NULL; 
	struct node *current = head; 
	while (current != NULL) 
	{ 
		struct node *next = current->next; 
		sort_insert(&sorted, current); 
		current = next; 
	} 
	head = sorted; 
}  

void push(struct node** head, int new) 
{ 
	struct node* new_node = malloc(sizeof(struct node)); 
	new_node->data = new; 
	new_node->next = *head;
	*head  = new_node; 
} 

int main()
{
	struct node *head = NULL;

	push(&head, 9); 
	push(&head, 3); 
	push(&head, 4); 
	push(&head, 8); 
	push(&head, 1); 

	printf("Linked list before bubble sorting : ");
	print_list(head);

	insertion_sort(head);

	printf("Linked list after bubble sorting : ");
	print_list(head);
}

