1
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
} *head, *front,*rear;

struct node* createNode(){
	return (struct node*)malloc(sizeof(struct node));
}
void insertLL(int val){
	struct node *new;
    new=createNode();
    new->data=val;
    new->next=NULL;
    if(head->next==NULL){
		head->next=new;
        front=new;
        rear=head;
    }
    rear->next=new;
    rear=new;
}
void deleteLL(){
    if(head->next==NULL){
		return;
	}
    printf("The deleted element is: %d\n",front->data);
    front=front->next;
    head->next=front;
}
void displayLL(){
    struct node *ptr;
	printf("The current Queue is: ");
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
void main(){
    int choice,num;
	head= createNode();
	head->next=NULL;
    front=rear=NULL;
	printf("Choose from the following:\n\t1.push an item to Queue\n");
	printf("\t2.Pop an item from Queue\n\t3.display Queue\n\t4.Exit\n");
	while(1){
		printf("\n\nEnter choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1: printf("Enter element to insert: ");
					scanf("%d",&num);
					insertLL(num);
					displayLL();
					break;
			case 2: deleteLL();
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