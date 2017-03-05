#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

//Deletion only allowed at the beginning

struct node
{
	struct node *next,*prev;
	int data;
};

typedef struct node node;

node *start=NULL,*end=NULL; //start->end = left->right

void insert_beg(int data);
void insert_end(int data);
void delete_beg();
void display();


int main()
{
	char c;
	int data;

	while(1)
	{
		printf("What do you want to do? \n a.Insert(at the beginning) \n b.Insert(at the end) \n c.Delete(first element) \n d.Display Queue \n e.Exit\n");
		scanf(" %c",&c);

		switch(c)
		{
			case 'a' :	printf("Enter the element to be inserted\n");
						scanf("%d",&data);

						insert_beg(data);
						printf("Element inserted \n");
						break;

			case 'b' :	printf("Enter the element to be inserted\n");
						scanf("%d",&data);
						insert_end(data);
						printf("Element inserted \n");
						break;

			case 'c' :	delete_beg();
						break;

			case 'd' :	display();
						break;

			case 'e' :	exit(0);

			default  :	printf("Invalid Input. Please try again\n");

		}

	}


}

void insert_beg(int data)
{
	node *new_node=(node *)malloc(sizeof(node));
	new_node->data=data;

	if(start==NULL)
	{
		start=end=new_node;
		start->next=start->prev=NULL;
	}
	else
	{
		new_node->prev=NULL;
		new_node->next=start;
		start->prev=new_node;
		start=new_node;
	}

}

void insert_end(int data)
{
	node *new_node=(node *)malloc(sizeof(node));

	new_node->data=data;

	if(start==NULL)
	{
		start=end=new_node;
		start->prev=start->next=NULL;
	}
	else
	{
		new_node->next=NULL;
		new_node->prev=end;
		end->next=new_node;
		end=new_node;
	}

}


void delete_beg()
{
	node *temp;
	if(start==NULL)
	{
		printf("The queue is empty. Please insert at least one node before performing deletion\n");
		return;
	}

	temp=start;

	printf("The element deleted is : %d \n",start->data);

	if(start==end)
	{
		start=end=NULL;
		free(temp);
	}
	else
	{
		start=start->next;
		start->prev=NULL;
		free(temp);
	}

}

void display()
{
	node *temp;

	if(start==NULL)
	{
		printf("The queue is empty. Nothing to display \n");
		return;
	}

	temp=start;

	while(temp!=end)
	{
		printf("%d -> ",temp->data);

		temp=temp->next;

	}
	printf("%d \n",temp->data);

}
