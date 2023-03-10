
#include <stdio.h>
#include <stdlib.h>
struct node{
	int pow;
	int coeff;
	struct node *link;
}node;

struct node* createNode(){
	return (struct node*)malloc(sizeof(struct node));
}
void displayPoly(struct node *head){
	struct node *ptr;
	if(head->link==NULL){
		printf("Polynimial Empty\n");
		return;
	}
	ptr=head->link;
	while(ptr->link!=NULL){
		printf("%dx^%d +",ptr->coeff,ptr->pow);
		ptr=ptr->link;
	}
	printf("%dx^%d\n",ptr->coeff,ptr->pow);
}
void inputPoly(struct node **head,int n){
	int i;
	struct node *ptr,*new;
	*head=createNode();
	ptr=createNode();
	if(n){
		(*head)->link=ptr;
		scanf("%d%d",&ptr->coeff,&ptr->pow);
		ptr->link=NULL;
		for(i=1;i<n;i++){
			new=createNode();
			scanf("%d%d",&new->coeff,&new->pow);
			new->link=NULL;
			ptr->link=new;
			ptr=ptr->link;
		}
	}
}
void sum(struct node *headA,struct node *headB,struct node **headS){
	struct node *ptrA,*ptrB,*ptrS;
	*headS=createNode();
	if(headA==NULL&&headB==NULL){
		printf("Polynomials empty: Sum is 0.\n");
		(*headS)->link=NULL;
		return;
	}
	ptrA=headA->link,ptrB=headB->link,ptrS=*headS;
	while(ptrA!=NULL&&ptrB!=NULL){
		ptrS->link=createNode();
		ptrS=ptrS->link;
		if(ptrA->pow==ptrB->pow){
			ptrS->coeff=ptrA->coeff+ptrB->coeff;
			ptrS->pow=ptrA->pow;
			ptrA=ptrA->link;
			ptrB=ptrB->link;
		}
		else if(ptrA->pow>ptrB->pow){
			*ptrS=*ptrA;
			ptrA=ptrA->link;
		}
		else{
			*ptrS=*ptrB;
			ptrB=ptrB->link;
		}
	}
	while(ptrA!=NULL){
		ptrS->link=createNode();
		ptrS=ptrS->link;
		*ptrS=*ptrA;
		ptrA=ptrA->link;
	}
	while(ptrB!=NULL){
		ptrS->link=createNode();
		ptrS=ptrS->link;
		*ptrS=*ptrB;
		ptrB=ptrB->link;
	}
	ptrS->link=NULL;
	printf("The sum is: ");
	displayPoly(*headS);
}
void remove_dup(struct node * head){
	struct node *i,*j,*dup;
	i=head;
	while(i->link!=NULL){ 
		j=i;
		while(j->link!=NULL){
			if(i->pow==j->link->pow){
				i->coeff=i->coeff+j->link->coeff;
				dup=j->link;
				j->link=j->link->link;
				free(dup);
			}
			else
				j=j->link;
		}
		i=i->link;
	}
}
void product(struct node *headA,struct node *headB,struct node **headP){
	struct node *ptrA,*ptrB,*ptrP;
	*headP=createNode();
	ptrA=headA->link;
	ptrP=*headP;
	while(ptrA!=NULL){
		ptrB=headB->link;
		while(ptrB!=NULL){
			ptrP->link=createNode();
			ptrP=ptrP->link;
			ptrP->coeff=(ptrA->coeff)*(ptrB->coeff);
			ptrP->pow=ptrA->pow+ptrB->pow;
			ptrB=ptrB->link;
		}
		ptrA=ptrA->link;
	}
	ptrP->link=NULL;
	remove_dup(*headP);
	printf("The product is: ");
	displayPoly(*headP);
}
int main(void){
	int n1,n2,choice=1;
	struct node *headA,*headB,*headS,*headP;
	printf("Enter number of terms in Polynomial A: ");
	scanf("%d",&n1);
	printf("Enter coefficients and Powers of Polyomial A: "); 
	inputPoly(&headA,n1);
	printf("Enter number of terms in Polynomial B: ");
	scanf("%d",&n2);
	printf("Enter coefficients and Powers of Polyomial B: "); 
	inputPoly(&headB,n2);
	printf("The polynommial A: ");
	displayPoly(headA);
	printf("The polynommial B: ");
	displayPoly(headB);
	sum(headA,headB,&headS);
	product(headA,headB,&headP);
}