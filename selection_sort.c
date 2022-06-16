#include<stdio.h>
#include<stdlib.h>

#define LIST_SIZE 5

struct node
{
	int data;
	struct node *link;
	struct node *head;
};

void print_list(struct node *ptr )
{
	while(ptr != NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->link;
	}
	printf("\n");
}

void swap(struct node *ptr1, struct node *ptr3)
{
	int temp = ptr1->data;
	ptr1->data = ptr3->data;
	ptr3->data = temp;
}


void selection_sort(struct node *head)
{
	struct node *ptr1 = head;
	struct node *ptr2 = NULL;
	struct node *ptr3;
	while (ptr1->link)
	{
		ptr3 = ptr1;
		ptr2 = ptr1->link;
		while(ptr2)
		{
			if(ptr3->data > ptr2->data)
			{
				ptr3 = ptr2;
			}
			ptr2 = ptr2->link;
		}
		swap(ptr1, ptr3);
		ptr1 = ptr1->link;
	}
}

int main()
{
	struct node *head = NULL;
	int arr[5] = {7, 8, 3, 1, 9};
	for(int i=0; i<LIST_SIZE; i++) 
	{
		struct node *ptr = NULL;
		ptr = malloc(sizeof(struct node));
		ptr->data = arr[i];
		ptr->link = head;
		head = ptr;
	}
	printf("Linked list before bubble sorting : ");
	print_list(head);
	selection_sort(head);
	printf("Linked list after bubble sorting : ");
	print_list(head);
}
