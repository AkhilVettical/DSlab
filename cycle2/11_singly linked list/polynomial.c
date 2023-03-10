#include<stdio.h>
#include<stdlib.h>

typedef struct poly {
    int coeff;
    int exp;
    struct poly* link;
} poly;
poly  *pstart=NULL;
poly *qstart=NULL;
poly *rstart=NULL;
int coeff, expo;
poly *newnode=NULL,*temp=NULL,*tempq=NULL,*tempr=NULL;
int p,q;
void polyadd()
{ 
temp=pstart;
tempq=qstart; 
newnode=(poly *)malloc(sizeof(poly));
rstart=newnode;
tempr=newnode;
while(temp->link!=NULL && tempq->link!=NULL)
   { if((temp->exp)==(tempq->exp))
      {
         tempr=newnode;
         tempr->coeff=temp->coeff+tempq->coeff;
         tempr->exp=temp->exp;
         temp=temp->link;
         tempq=tempq->link;
         newnode=(poly *)malloc(sizeof(poly));
         tempr->link=newnode;
      }
      else if((temp->exp)>(tempq->exp))
      {
        tempr=newnode;
        tempr->coeff=temp->coeff;
        tempr->exp=temp->exp;
        temp=temp->link;
        newnode=(poly *)malloc(sizeof(poly));
        tempr->link=newnode;
      }
      else{
        tempr=newnode;
        tempr->coeff=tempq->coeff;
        tempr->exp=tempq->exp;
        tempq=tempq->link;
        newnode=(poly *)malloc(sizeof(poly));
        tempr->link=newnode;
      }
}
if(temp->link!=NULL)
{

    while(temp->link!=NULL)
    {   
        tempr=newnode;
        tempr->coeff=temp->coeff;
        tempr->exp=temp->exp;
        temp=temp->link;
        newnode=(poly *)malloc(sizeof(poly));
        tempr->link=newnode;
    }
}
if(tempq->link!=NULL)
{
    while(tempq->link!=NULL)
    {   
        tempr=newnode;
        tempr->coeff=tempq->coeff;
        tempr->exp=tempq->exp;
        tempq=tempq->link;
        newnode=(poly *)malloc(sizeof(poly));
        tempr->link=newnode;
    }
}
tempr=rstart;
while(tempr->link!=NULL)
      {
        printf("%dx^%d+",tempr->coeff,tempr->exp);
        tempr=tempr->link;
      }
      printf("0\n");
}

void input()
{
    printf("Enter the number of terms in the polynomial 1: ");
    scanf("%d",&p);
    printf("Enter the number of terms in the polynomial 2: ");
    scanf("%d",&q);
    printf("Enter the  polynomial 1: ");
    if(p!=0)
    {

        pstart=newnode;
        for(int i=1;i<=p;i++)
        {      newnode=(poly *)malloc(sizeof(poly));
               scanf("%d %*c %*c %d",&coeff,&expo);
               temp=newnode;
               temp->coeff=coeff;
               temp->exp=expo;

               temp->link=newnode;
        }
    }
    printf("Enter the polynomial 2: ");
    if(q!=0)
    {
        newnode=(poly *)malloc(sizeof(poly));
        qstart=newnode;
        tempq=newnode;
        for(int i=1;i<=q;i++)
        {   
               temp=newnode;           
               scanf("%d %*c %*c %d",&coeff,&expo);
               tempq->coeff=coeff;
               tempq->exp=expo;
               newnode=(poly *)malloc(sizeof(poly));
               temp->link=newnode;
 
        }
    }

}

void polymulti()
{

}
void main()
{   
    int choice;
    printf("1.Polynomial Addition\n2.Polynomial multiplication\n3.Exit\n");
    scanf("%d",&choice);
    do{
        switch(choice)
        {
            case 1:{input();polyadd();break;}
            case 2:{input();polymulti();break;}
            case 3:return;
            default:{printf("Inavalid Option\n");break;}
        }
    }while(choice!=3);
}