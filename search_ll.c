#include<stdio.h>
#include<stdlib.h>

#define NODE_SIZE 5

typedef struct node
{
	int data;
	struct node *link;
}slist;

slist *head = NULL;

void insert(int data)
{
	slist *new = malloc(sizeof(slist));
	if(new == NULL)
	{
		printf("Memory is not allocated\n");
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
			slist *temp = head;
			while(temp->link != NULL)
			{
				temp = temp->link;
			}
			temp->link = new;
		}
	}
}

void display()
{
	slist *temp = head;
	if(head == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		printf("LIST IS : ");
		while(temp != NULL)
		{
			printf("%d ", temp->data);
			temp = temp->link;
		}
		printf("\n");
	}
}

int search(int element)
{
	if(head == NULL)
	{
		printf("LIST IS EMPTY\n");
	}
	else
	{
		printf("Enter the element to searched : ");
		scanf("%d", &element);
		slist *temp = head;
		while(temp != NULL)
		{
			if(temp->data == element)
			{
				printf("ELEMENT FOUND\n");
				return 0;
			}
			else
			{
				temp=temp->link;
			}
		}
		printf("SEARCHED ELEMENT NOT FOUND\n");
	}
}


int main()
{
	int data, element, i=0;
	while(i++<NODE_SIZE)
	{
		printf("Enter data : ");
		scanf("%d", &data);
		insert(data);
	}
	display();
	search(element);
}

