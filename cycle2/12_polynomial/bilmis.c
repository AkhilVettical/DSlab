#include<stdio.h>
#include<stdlib.h>
typedef struct poly{
    int coeff,expo;
    struct poly *link;
}poly;

void input(poly *a,int n)
{
    poly *ptr=a;
    for(int i=0;i<n;i++)
    {
        printf("enter the ele");
        poly *new=(poly*)malloc(sizeof(poly));
        scanf("%d %d",&new->coeff,&new->expo);
        ptr->link=new;
        new->link=NULL;
        ptr=ptr->link;      
    }
}
void display(poly *a)
{
    poly *ptr=a->link;
    while(ptr!=NULL){
    printf("%d*X%d + ",ptr->coeff,ptr->expo);
    ptr=ptr->link;
    }
    printf("\n");
}
void multi(poly * a,poly*b,poly *c)
{
    poly *p1=a->link;
    poly *p2;
    poly *p3=c;
    while(p1!=NULL)
    {
        p2=b->link;
        while(p2!=NULL)
        {      
            poly *new=(poly*)malloc(sizeof(poly));
            p3->link=new; 
             new->coeff=(p1->coeff)*(p2->coeff);
             new->expo=(p1->expo)+(p2->expo);
             new->link=NULL;
            p2=p2->link;  
        }
        p1=p1->link;
    }
    p3->link=NULL;
    display(c);
           
// poly *i,*j,*temp;
//     i=c,temp=c;
//     while(i->link!=NULL){
//         j=i;
//         while(j->link!=NULL){
//             if(i->expo==j->link->expo)
//             {
//                i->coeff=i->coeff+j->coeff;
//                temp=j->link;
//                j->link=j->link->link;
//                free(temp);
//             }
//             else
//                 j=j->link;
//         }
//         i=i->link;
//     }
}
void main(){
    int n,m;
    poly *a=(poly*)malloc(sizeof(poly));
    poly *b=(poly*)malloc(sizeof(poly));
    poly *c=(poly*)malloc(sizeof(poly));
    poly *a1=a;
    poly *b1=b;
    poly *c1=c;
    printf("hi");
    scanf("%d",&n);
    input(a1,n);
    scanf("%d",&m);
    input(b1,m);
    printf("dipla");
    display(a);
    display(b);
    a1=a,b1=b;
    multi(a1,b1,c1);
    
}