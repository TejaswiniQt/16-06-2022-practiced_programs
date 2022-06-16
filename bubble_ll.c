#include<stdio.h>
#include<stdlib.h>

#define LIST_SIZE 5

struct node
{
	int data;
	struct node *link;
};

struct node *head = NULL;
void print_list()
{
	struct node *ptr = head;
	while(ptr != NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->link;
	}
	printf("\n");
}

void swap(struct node *ptr1, struct node *ptr2)
{
	int temp = ptr1->data;
	ptr1->data = ptr2->data;
	ptr2->data = temp;
}

void bubble_sort()
{
	struct node *ptr1 = NULL;
	struct node *ptr2 = NULL;
	int sum;
	do 
	{
		sum=0;
		ptr1 = head;
		while (ptr1->link != ptr2)
		{
			if (ptr1->data > ptr1->link->data)
			{ 
				swap(ptr1, ptr1->link);
				sum = 1;
			}
			ptr1 = ptr1->link;
		}
		ptr2 = ptr1;
	}while(sum);

}

void insert(int data)
{
	struct node *temp;
	struct node *new = (struct node*)malloc(sizeof(struct node));
	if(new == NULL)
	{
		printf("Memory not allocated\n");
	}
	else
	{
		new->data = data;
		new->link = NULL;
		if(head == NULL)
		{
			head = new;
		}
		else
		{
			temp = head;
			while(temp->link != NULL)
			{
				temp = temp->link;
			}
			temp->link = new;
		}
	}
}


int main()
{
	struct node *head = NULL;
	int arr[5] = {7, 8, 3, 1, 9};
	for(int i=0; i<LIST_SIZE; i++) 
	{
		insert(arr[i]);
	}
	printf("Linked list before bubble sorting : ");
	print_list();
	bubble_sort();
	printf("Linked list after bubble sorting : ");
	print_list();
}


