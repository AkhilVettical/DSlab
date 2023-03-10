#include<stdio.h>


#define MAX_TERMS 101


typedef struct {

int row;

int col;

int value;

} term;


term t1[MAX_TERMS];

term t2[MAX_TERMS];

term sum[MAX_TERMS];

term t[MAX_TERMS];

//int avail=0;



void convert(int a[][10],int m,int n,term t[])

{

int i,j;

int k=0;

t[k].row=m;

t[k].col=n;

k=1;

for(i=0;i<m;i++)

for(j=0;j<n;j++)

{

if(a[i][j]!=0)

{

t[k].row=i;

t[k].col=j;

t[k].value=a[i][j];

k++;

}

}

t[0].value=k-1;


}


void display(term t[])

{

printf("Row Col Values\n");

for(int i=0;i<=t[0].value;i++)

printf("%d %d %d\n",t[i].row,t[i].col,t[i].value);

}

void readmatrix(int a[][10],int m,int n)

{

for(int i=0;i<m;i++)

for(int j=0;j<n;j++)

scanf("%d",&a[i][j]);

}


void fasttranspose(term t1[],term t[])

{

int numcols,numterms,j;

numcols=t1[0].col;

numterms=t1[0].value;

t[0].row=numcols;

t[0].value=numterms;

t[0].col=t1[0].row;

int rowterms[20],startpos[20];

int i;

for(i=0;i<numcols;i++)

rowterms[i]=0;

for(i=1;i<=numterms;i++)

{

rowterms[t1[i].col]++;

}

startpos[0]=1;

for(i=1;i<numcols;i++)

{

startpos[i]=startpos[i-1]+rowterms[i-1];

}

for(i=1;i<=numterms;i++)

{

j=startpos[t[i].col]++;

t[j].row=t1[i].col;

t[j].col=t1[i].row;

t[j].value=t1[i].value;

}

}


void add(term t1[],term t2[],term sum[]){

int r1=t1[0].row,c1=t1[0].col,r2=t2[0].row,c2=t2[0].col,m=1,n=1,s=1;

int i,j;

if(r1!=r2 || c1!=c2){

return;

}

else{

sum[0].row=r1;sum[0].col=c1;

for(i=0;i<r1;i++)

for(j=0;j<c1;j++)

if (t1[m].row==i && t1[m].col==j && t2[n].row==i && t2[n].col==j){

sum[s].row=t1[m].row;

sum[s].col=t1[m].col;

sum[s].value=t1[m].value+t2[n].value;

m++;n++;s++;

}

else if (t1[m].row==i && t1[m].col==j){

sum[s].row=t1[m].row;

sum[s].col=t1[m].col;

sum[s].value=t1[m].value;

m++;s++;

}






else if (t2[n].row==i && t2[n].col==j){

sum[s].row=t2[n].row;

sum[s].col=t2[n].col;

sum[s].value=t2[n].value;

n++;s++;

}

sum[0].value=s-1;

}

}


void main()

{

for(int l=0;l<MAX_TERMS;l++)

{

t1[l].row=0;

t1[l].col=0;

t1[l].value=0;

}

int choice;

int a[10][10];

int b[10][10];

int m,n,p,q;

printf("1.READ TWO MATRIX AND DISPLAY X\n2.TRANSPOSE AND DISPLAY\n3.SUM AND DISPLAY\n4.EXIT\n");

do

{

scanf("%d",&choice);

switch(choice)

{

case 1:{

printf("Enter the order of matrix A:");

scanf("%d %d",&m,&n);

printf("Enter the elements of matrix A\n");

readmatrix(a,m,n);

printf("Enter the order of matrix B: ");

scanf("%d %d",&p,&q);

printf("Enter the elements of matix B\n");

readmatrix(b,p,q);

convert(a,m,n,t1);

convert(b,p,q,t2);

display(t1);

display(t2);

break;

}

case 2:{

printf("Enter the order of matrix A:");

scanf("%d %d",&m,&n);

printf("Enter the elements of matrix A\n");

readmatrix(a,m,n);

convert(a,m,n,t1);

fasttranspose(t1,t);

display(t);

break;

}

case 3:{ printf("Enter the order of matrix A:");

scanf("%d %d",&m,&n);

printf("Enter the elements of matrix A\n");

readmatrix(a,m,n);

printf("Enter the order of matrix B: ");

scanf("%d %d",&p,&q);

printf("Enter the elements of matix B\n");

readmatrix(b,p,q);

if(m!=p||n!=q)

printf("Addition not possible\n");

else

{

convert(a,m,n,t1);

convert(b,p,q,t2);

add(t1,t2,sum);

display(sum);

}

break;

}

case 4:{

return ;

}

}

}while(choice!=4);



}