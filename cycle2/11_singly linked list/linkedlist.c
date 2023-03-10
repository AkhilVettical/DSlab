#include <stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node* link;
};
struct node* start = NULL;
void createlist()
{
	if(start==NULL)
	{
	int n;	
	printf("\nEnter the number of nodes: ");
    scanf("%d",&n);
    if(n!=0)
    {
    	int data;
    	struct node* newnode;
    	struct node* temp;
    	newnode= malloc(sizeof(struct node));
    	start=newnode;
    	temp=start;
    	printf("\nEnter number to be inserted: ");
    	scanf("%d",&data);
    	start->info = data;
    	for(int i=2;i<=n;i++)
    	{
    		newnode = malloc(sizeof(struct node));
    		temp->link =newnode;
    		printf("\nEnter number to be inserted :");
    		scanf("%d",&data);
    		newnode->info=data;
    		temp=temp->link;

    	}
    temp->link=NULL;
    printf("The list is created\n");
    }
   }
  else 
  	printf("\nThe list is already created\n");
}

void insertfront()
{
	int data;
	struct node* temp;
	temp= malloc(sizeof(struct node));
	printf("\nEnter number to be inserted: ");
	scanf("%d",&data);
	temp->info=data;
	temp->link=start;
	start=temp;
}

void insertend()
{
	int data;
	struct node *temp, *head;
	temp=malloc(sizeof(struct node));
	printf("Enter number to be inserted :");
	scanf("%d",&data);
	temp->link=NULL;
	temp->info=data;
	head=start;
	while(head->link!=NULL)
		head=head->link;
	head->link=temp;

}
void insertpos()
{
	int data,key;
	struct node *temp, *head;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the element after which the element should be inserted: ");
	scanf("%d",&key);
	printf("Enter the number to be inserted: ");
	scanf("%d",&data);
	head=start;
	while(head->info!=key && head->link!=NULL)
		head=head->link;
	if(head->link==NULL && head->info!=key)
		printf("The key is not available in the list\n");
	else
		temp->link=head->link;
		temp->info=data;
		head->link=temp;
}

void deletefront()
{
	struct node* temp;
	if(start==NULL)
		printf("The liked list is empty\n");
	else
	{
		temp=start;
		start=start->link;
	}
		
}
void deleteend()
{
	struct node *temp, *prevnode;
	if(start==NULL)
		printf("\nList is empty\n");
	else {
		temp=start;
		while(temp->link!=NULL)
		{
			prevnode=temp;
			temp=temp->link;
		}
	}
	prevnode->link=NULL;
}

void deletepos()
{
	struct node *temp, *prev;
	int i=1,key;
	if(start==NULL)
		printf("List is empty\n");
	printf("Enter the element  which  should be deleted: ");
	scanf("%d",&key);
	temp=start;
	while(temp->info!=key && temp->link!=NULL)
		{prev=temp;
		temp=temp->link;
	}
	if(temp->link==NULL && temp->info!=key)
		printf("The key is not available in the list\n");
	else 
	{
	 prev->link=temp->link;
	}
}
void display()
{
	struct node *temp;
	temp=start;
	while(temp->link!=NULL)
		{printf("%d ",temp->info);
			temp=temp->link;
		}
		printf("%d ",temp->info);
}


void main()
{
  int choice;
   printf("\n 1. INSERT AT FRONT\n 2.INSERT AT END\n 3.INSERT AT SPECIFIED POSITION\n 4.DELETE FROM SPECIFIED POSITION ");
   printf("\n 5.DELETE FROM FRONT\n 6.DELETE FROM END\n 7.DISPLAY\n 8.EXIT");
  createlist();
  do 
  {
  	printf("\nEnter the choice: ");
  	scanf("%d",&choice);
  	switch(choice)
  	{
  		case 1:insertfront();break;
  		case 2:insertend();break;
  		case 3:insertpos();break;
  		case 4:deletepos();break;
  		case 5:deletefront();break;
  		case 6:deleteend();break;
  		case 7:display();break;
  		case 8:return ;break;
  		default:printf("INVALID INPUT\n"); break;
  	}
  }while(choice!=8);
}
