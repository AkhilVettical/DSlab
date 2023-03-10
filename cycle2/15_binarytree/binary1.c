#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*rchild;
	struct node*lchild;
}*temp,*head,*new,*ptr,*LC,*RC,*k,*ptrr,*ptrl,*parent;
void create(struct node*,int);
void insert();
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
struct node* search_parent(struct node*,struct node*,int);
void delete(struct node*,int);
void main()
{
	int c,l,d;
	char ch='y';
	while(ch=='y' || ch=='Y')
	{
		printf("1.Insert node\n2.Inorder\n3.Preorder\n4.Postorder\n5.Delete\n6.Exit\n");
		printf("Input choice\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
			{
				head=(struct node*)malloc(sizeof(struct node));
				printf("Enter data of root\n");
				scanf("%d",&d);
				create(head,d);
				break;
			}
			case 2:
			{
				temp=head;
				inorder(temp);
				printf("\n");
				break;
			}
			case 3:
			{
				temp=head;
				preorder(temp);
				printf("\n");
				break;
			}
			case 4:
			{
				temp=head;
				postorder(temp);
				printf("\n");
				break;
			}
			case 5:
			{
				int e;
				printf("Element to be deleted\n");
				scanf("%d",&e);
				delete(head,e);
				break;
			}
			case 6:
			{
				exit(0);
				break;
			}
			default:
			{
				printf("Invalid choice\n");
			}
		}
		printf("Do you wish to continue\n");
		scanf(" %c",&ch);
	}
}
void create(struct node*ptr,int item)
{
	int x;
	char ch;
	if(ptr!=NULL)
	{
		ptr->data=item;
		printf("If %d has left subtree\n",item);
		scanf(" %c",&ch);
		if(ch=='y'||ch=='Y')
		{
			LC=(struct node*)malloc(sizeof(struct node));
			ptr->lchild=LC;
			printf("Enter data of node\n");
			scanf("%d",&x);
			create(LC,x);
		}
		else
		{
			LC=(struct node*)malloc(sizeof(struct node));
			LC=NULL;
			ptr->lchild=NULL;
		}
		printf("If %d has right subtree\n",item);
		scanf(" %c",&ch);
		if(ch=='y'||ch=='Y')
		{
			RC=(struct node*)malloc(sizeof(struct node));
			ptr->rchild=RC;
			printf("Enter data of node\n");
			scanf("%d",&x);
			create(RC,x);
		}
		else
		{
			RC=(struct node*)malloc(sizeof(struct node));
			RC=NULL;
			ptr->rchild=NULL;
		}
	}
}
void inorder(struct node*temp)
{

	if(temp!=NULL)
	{
		inorder(temp->lchild);
		printf("%d  ",temp->data);
		inorder(temp->rchild);
	}
}
void preorder(struct node*temp)
{

	if(temp!=NULL)
	{
		printf("%d  ",temp->data);
		preorder(temp->lchild);		
		preorder(temp->rchild);
	}
}
void postorder(struct node*temp)
{

	if(temp!=NULL)
	{
		postorder(temp->lchild);		
		postorder(temp->rchild);
		printf("%d  ",temp->data);
	}
}
void delete(struct node* head,int key)
{
	if (head == NULL)
	{
		printf("\n\nTree is Empty\n\n");
		return ;
	}
	parent = search_parent(head,NULL,key);
	if (parent == NULL)
		printf("\nKey not Found!!\n");
	else
	{
		ptrl = parent->lchild;
		ptrr = parent->rchild;
		if (ptrl != NULL)
		{
			if (ptrl->data == key)
				if(ptrl->lchild == NULL && ptrl->rchild==NULL)
					parent->lchild = NULL;
				else
				{
					printf("\nElement cannot be deleted!!!\n");
					return ;
				}
		}
		if (ptrr!=NULL)
		{
			if (ptrr->data == key)
				if(ptrr->lchild == NULL && ptrr->rchild==NULL)
					parent->rchild = NULL;
				else
				{
					printf("\nElement cannot be deleted!!!\n");
					return ;
				}
		}
	}
}
struct node* search_parent(struct node* ptr,struct node* prev,int key)
{
	if (ptr == NULL)
		return NULL;
	if (ptr->data == key)
	{
		k = prev;
		return prev;
	}
	else
	{
		search_parent(ptr->lchild,ptr,key);
		search_parent(ptr->rchild,ptr,key);
	}
	return k;
}