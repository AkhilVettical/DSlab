#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node  *lc,*rc;
};
 struct node* create()
 {  
    int x;
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data(-1 for no node)");
    scanf("%d",&x);
    if(x==-1)
     {return 0;}
     newnode->data=x;
     printf("Enter left child of %d: ",x);
     newnode->lc=create();
     printf("Enter right child of %d: ",x);
     newnode->rc=create();

     return newnode;
 }
void preorder(struct node* root)
{
if(root==0)
{return ;}
printf("%d ",root->data);
preorder(root->lc);
preorder(root->rc);
}
void inorder(struct node* root)
{
    if(root==0)
    {return ;}
inorder(root->lc);
printf("%d ",root->data);
inorder(root->rc);
}
void postorder(struct node* root)
{
    if(root==0)
    {return ;}
postorder(root->lc);
postorder(root->rc);
printf("%d ",root->data);
}
void main()
{   
    int choice;
    int item;
    struct node* root;
    root=NULL;
    root=create();
    printf("1.Insert\n2.Inorder\n3.Preorder\n4.PostOrder\n");
    do{
        printf("Enter choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        {   printf("Enter the item after which the element is to be inserted: ");
            scanf("%d",&item);
            insertbinarytree_link(root,item);
            break;
        }
        case 2:
        {
            inorder(root);
            printf("\n");
            break;
        }      
        case 3:
        {
            preorder(root);
            printf("\n");
            break;
        }
        case 4:
        {
            postorder(root);
            printf("\n");
            break;
        }
        case 5:return;
    }
    }while(choice!=5);
}

struct node* search_LINK(struct node* root,int item)
{   
    if(root == NULL)
        return NULL;
    if(root->data==item)
        return root;

    if(search_LINK(root->lc,item))
        return search_LINK(root->lc,item);

    return search_LINK(root->rc, item);
}
void insertbinarytree_link(struct node* root,int item)
{   int element;
    struct node* ptr;
    struct node* newnode;
    char option;
    ptr=search_LINK(root,item);
    if(ptr==NULL)
    {
        printf("Search is unsucessful");
        return;
    }
    else 
    {
            printf("Enter the element: ");
            scanf("%d",&element);
        if(ptr->lc==NULL||ptr->rc==NULL)
        {
           printf("(L/R)\n");
           scanf(" %c",&option);
           if(option=='L')
           {

            if(ptr->lc==NULL)
            {
                newnode=(struct node*)malloc(sizeof(struct node));
                newnode->data=element;
                newnode->lc=NULL;
                newnode->rc=NULL;
                ptr->lc=newnode;
            }
            else 
            printf("Insertion is not possible in the left child\n");
           }
           else 
           {
            if(ptr->rc==NULL)
            {
                newnode=(struct node*)malloc(sizeof(struct node));
                newnode->data=element;
                newnode->lc=NULL;
                newnode->rc=NULL;
                ptr->rc=newnode;
            }
            else 
            printf("Insertion is not possible in the right child\n");
           }
        }
        else 
        printf("The key node has no empty node\n");
    }
}

struct node* Search_Parent(struct node* ptr,int item, struct node* prev)
{
    if(ptr==NULL)
      return NULL;
      if(ptr->data==item)
      {
        return prev;
      }
      else 
      {
        prev=Search_Parent(ptr->lc,item,ptr);
        prev=Search_Parent(ptr->rc,item,ptr);
      }
return prev;

}
void Deletebintree(struct node* root,int item)
{   
    struct node* parent;
    struct node* ptr;
    struct node* ptr1;
    struct node* ptr2;

    ptr=root;
    if(ptr=NULL)
    printf("Tree is empty\n");
    parent=Search_Parent(root,item,NULL);
   if(parent!=NULL)
   {
     ptr1=parent->lc;
     ptr2=parent->rc;
     
   }

}

