/*
14-09-2022
length of longest substring 
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
    char firstname[20];
    char middlename[20];
    char lastname[20];
    long accNo;
    char accType[5];
    int balance;
} customer;

customer tempc;
 char option;

void input(customer *a,int n)
{
    int i;
printf("Input the details of n customers: ");
for(i=0;i<n;i++)
{
printf("FIRST NAME: ");
scanf("%s",(a+i)->firstname);
printf("MIDDLE NAME: ");
scanf("%s",(a+i)->middlename);
printf("LAST NAME: ");
scanf("%s",(a+i)->lastname);
printf("Enter the account number: ");
scanf("%ld",(a+i)->accNo);
printf("Enter the account type: ");
scanf("%s",(a+i)->accType);
printf("Enter the Balance Amount: ");
scanf("%d",(a+i)->balance);
}
}

void search(customer *a,int n)
{
int i;
long accNos;
printf("Enter the accNo to be searched: ");
scanf("%ld",&accNos);
for(i=0;i<n;i++)
{
    if((a+i)->accNo==accNos)
        printf("Customer found in the database. ");
    else 
        printf("Customer not found in the database!!");
    
}
}

int balance(customer *a,int n)
{
int i;
long accNos;
printf("Enter the accNO whose balance needs to be retrieved: ");
scanf("%ld",&accNos);
for(i=0;i<n;i++)
if((a+i)->accNo==accNos)
printf("Balance:%d",(*(a+i)).accNo);
}

void sort(customer *a,int n)
{
int i,j;
char temp[20];
for(i=0;i<n-1;i++)
 for(j=i+1;j<n;j++)
  if(strcasecmp((a+i)->firstname,(a+j)->firstname)<0)
  {
   tempc=*(a+i);
   *(a+i)=*(a+j);
   *(a+j)=tempc;

    /* 
     strcpy(temp,c[i].firstname);
     strcpy(c[i].firstname,c[j].firstname);
     strcpy(c[j].firstname,temp);
     */
  }
}
  
  void display(customer *a,int n)
  {
    int i;
  for(i=0;i<n;i++)
  {
  if(option=='d' && strcmp((*(a+i)).accType,"FD")!=0)
   continue;
   printf("FIRST NAME: %s",(*(a+i)).firstname);
   printf("MIDDLE NAME: %s",(*(a+i)).middlename);
   printf("LAST NAME: %s",(*(a+i)).lastname);
   printf("ACC NO: %ld",(*(a+i)).accNo);
   printf("ACCOUNT TYPE: %s",(*(a+i)).accType);
   printf("BALANCE: %d",(*(a+i)).balance);

}
  }
void main()
{ 
int n; 
customer *a; 
char choice; 

printf("Enter the number of customers: ");
scanf("%d",&n);
a=(customer *) malloc(sizeof(customer)*n);
input(a,n);
do{
printf("a)Search for a particular customer based on accNO\n");
printf("b)Retrieve the balance of a customer whose accNo is specified\n");
printf("c)Display a list of customers sorted in the alphabetical order of their first name\n");
printf("d)List the name,accNo and balance of all customers whose account type is FD\n");
printf("Press a,b,c or d\n");
scanf(" %c",&option);
switch(option)
{
    case 'a':search(a,n);
    case 'b':balance(a,n);
    case 'c':{
              sort(a,n);
              printf("List of customers in alphabetical order of their first name\n");
              display(a,n);
             }
    case 'd':display(a,n);
    default :printf("Enter a valid option\n");
              
}
printf("Do you want to continue:(Y/N) ");
scanf("%c",&choice);
}
while(choice=='y'||choice=='Y');

}





