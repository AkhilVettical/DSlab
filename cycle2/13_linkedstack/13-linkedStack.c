
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}stack;
stack *head, *top;
stack* createNode(){
	return malloc(sizeof(stack));
}
void popLL()
{
	stack *ptr;
	if(head->next==NULL){
		printf("Stack Empty\n");
		return;
	}
	printf("The deleted element is: %d\n",top->data);
	ptr=head;
	while(ptr->next!=top){
		ptr=ptr->next;
	}
	ptr->next=NULL;
	free(top);
	top=ptr;
}
void pushLL(int item)
{
	stack *new;
	new=createNode();
	new->data=item;
	new->next=NULL;
	if(head->next==NULL){
		top=head;
	}
	top->next=new;
	top=new;
}
void displayLL()
{
	stack *ptr;
	printf("The current stack is: ");
	if(head->next==NULL){
		printf("Stack Empty\n");
		return;
	}
	ptr=head->next;
	while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
}
void main()
{
	int choice,num;
	head= createNode();
	head->next=NULL;
	printf("Choose from the following:\n\t1.push an item to stack\n");
	printf("\t2.Pop an item from stack\n\t3.display stack\n\t4.Exit\n");
	while(1)
	{
		printf("\n\nEnter choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter Item to push: ");
					scanf("%d",&num);
					pushLL(num);
					displayLL();
					break;
			case 2: popLL();
					displayLL();
					break;
			case 3: displayLL();
					break;
			case 4: break;
			default: printf("Invalid Input\n");
		}
		if(choice == 4)
			break;
	}
}