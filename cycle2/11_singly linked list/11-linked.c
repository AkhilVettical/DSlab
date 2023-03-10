
#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *link;
};
struct node *head;

struct node* createNode(){
	return (struct node*)malloc(sizeof(struct node));
}
void insertBegin(int val){
	struct node *new;
	new=createNode();
	if(new==NULL){
		printf("Memory Underflow: No Insertion\n");
		return;
	}
	new->link=head->link;
	new->data=val;
	head->link=new;
}
void insertEnd(int val){
	struct node *new;
	new=createNode();
	if(new==NULL){
		printf("Memory Underflow: No Insertion\n");
		return;
	}
	struct node *ptr;
	ptr=head;
	while(ptr->link!=NULL)
		ptr=ptr->link;

	ptr->link=new;
	new->data=val;
	new->link=NULL;
}
void insertPos(int val,int key){
	struct node *new;
	new=createNode();
	if(new==NULL){
		printf("Memory Underflow: No Insertion\n");
		return;
	}
	struct node *ptr;
	ptr=head;
	while(ptr->data!=key&&ptr->link!=NULL)
		ptr=ptr->link;
	if(ptr->data==key){
		new->link=ptr->link;
		new->data=val;
		ptr->link=new;
		return;
	}
	printf("Key is not available in the list\n");
}
void deletePos(int key){
	struct node *ptr,*ptr1;
	if(head->link==NULL){
		printf("List Empty: cannot delete\n");
		return;
	}
	ptr1=head;
	ptr=ptr1->link;
	while(ptr!=NULL)
		if(ptr->data==key){
			ptr1->link=ptr->link;
			free(ptr);
			return;
		}
		else{
			ptr1=ptr;
			ptr=ptr->link;
		}
	printf("Key is not available in the list\n");

}
void deleteBegin(){
	struct node *ptr;
	if(head->link==NULL){
		printf("List Empty: cannot delete\n");
		return;
	}
	ptr=head->link;
	head->link=ptr->link;
	printf("Deleted Data is: %d\n",ptr->data);
	free(ptr);
}
void deleteEnd(){
	struct node *ptr,*ptr1;
	if(head->link==NULL){
		printf("List Empty: cannot delete\n");
		return;
	}
	ptr1=head;
	ptr=ptr1->link;
	while(ptr->link!=NULL){
		ptr1=ptr;
		ptr=ptr->link;
	}
	ptr1->link=NULL;
	printf("Deleted Data is: %d",ptr->data);
	free(ptr);		
}
void displayLL(){
	struct node *ptr;
	if(head->link==NULL){
		printf("\nList Empty\n");
		return;
	}
	ptr=head->link;
	printf("The current linked list is: ");
	while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr=ptr->link;
	}
	printf("\n");
}
int main(void){
	int choice,num,key;
	head=createNode();
	head->link=NULL;
	printf("Options:\n\t");
	printf("1.Inser at begining\n\t2.Insert at End\n\t");
	printf("3.Insert at specific position\n\t");
	printf("4.Delete from a specific position\n\t5.Delete from Begining\n\t");
	printf("6.Delete from End\n\t7.Exit\n");
	while(1)
	{
		printf("\nEnter choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter data: ");
					scanf("%d",&num);
					insertBegin(num);
					break;
			case 2: printf("Enter data: ");
					scanf("%d",&num);
					insertEnd(num);
					break;
			case 3: printf("Enter data: ");
					scanf("%d",&num);
					printf("Enter key after which node is to be inserted: ");
					scanf("%d",&key);
					insertPos(num,key);
					break;
			case 4: printf("Enter data of node that is to be deleted: ");
					scanf("%d",&key);
					deletePos(key);
					break;
			case 5: deleteBegin();
					break;
			case 6: deleteEnd();
				break;
			case 7: break;
			default: printf("Invalid input\n");
		}
		if(choice==7)
			break;
		displayLL();
	}
		
}