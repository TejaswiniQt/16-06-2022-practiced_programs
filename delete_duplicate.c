#include<stdio.h>
#include<stdlib.h>
struct sll
{
	int data;
	struct sll *link;
};
struct sll *head = NULL;
void insert(int data);
void print();
void duplicate();

int main()
{
	int data,i=0;
	while(i++<=5)
	{
		printf("Enter data : \n");
		scanf("%d", &data);
		insert(data);
	}
	print();
	duplicate();
	print();
}

void duplicate()
{
	struct sll *temp=NULL;
	struct sll *curr=head;
	struct sll *index=NULL;

	while(curr != NULL)
	{
		temp = curr;
		index = curr->link;
		while(index != NULL)
		{
			if(curr->data == index->data)
			{
				temp->link = index->link;
			}
			else
			{
				temp = index;
			}
			index = index->link;
		}
		curr = curr->link;
	}
}

void insert(int data)
{
	struct sll *temp;
	struct sll *new = (struct sll *)malloc(sizeof(struct sll));
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

void print()
{
	if(head == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		struct sll *temp = head;
		while(temp != NULL)
		{
			printf("%d ", temp->data);
			temp = temp->link;
		}
		printf("\n");
	}
}

