#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int front=-1,rear=-1,maxsize;
int *cqueue;
void renqueue(int x)
{
if((front==0&rear==maxsize-1)||(rear+1==front))
{printf("CIRCULAR QUEUE OVERFLOW\n");
return;
}
else if(front==-1)
{
front=rear=0;
cqueue[rear]=x;
}

else
{rear=(rear+1)%maxsize;
cqueue[rear]=x;
}

}

void fdequeue()
{
if(front==-1)
printf("CIRCULAR QUEUE UNDERFLOW\n");
else if(front==rear)
{
printf("The deleted element: %d\n",cqueue[front]);
front=rear=-1;
}

else {
printf("The deleted element: %d\n",cqueue[front]);
front=(front+1)%maxsize;
}

}


void fenqueue(int x)

{

if((front==0&rear==maxsize-1)||(rear+1==front))

{printf("CIRCULAR QUEUE OVERFLOW\n");

return;

}

else if(front==-1)

{front=rear=0;

cqueue[rear]=x;

}

else

{rear=(rear+1)%maxsize;

cqueue[rear]=x;

}

}



void rdequeue()

{


if(front==-1)

printf("CIRCULAR QUEUE UNDERFLOW\n");

else if(front==rear)

{

printf("The deleted element: %d\n",cqueue[front]);

front=rear=-1;

}


else {

printf("The deleted element: %d\n",cqueue[front]);

front=(front+1)%maxsize;

}

}

void display()

{

int i;

if(front==-1)

printf("The circular queue is empty\n");

else{

if(front<=rear)

for(i=front;i<=rear;i++)

printf("%d ",cqueue[i]);

else

{
for(i=front;i<=maxsize-1;i++)

printf("%d ",cqueue[i]);

for(i=0;i<=rear;i++)

printf("%d ",cqueue[i]);

}

printf("\n");

}

}


void main()

{ int choice,element;

printf("Enter the maxsize of the queue: ");

scanf("%d",&maxsize);

cqueue= (int*) malloc(maxsize*sizeof(int));

printf("1.R-ENQUEUE \n2.F-DEQUEUE\n3.F-ENQUEUE\n4.R-DEQUEUE\n5-DISPLAY\n6-EXIT");

printf("Enter the choice: ");

do{

scanf("%d",&choice);

switch(choice)

{

case 1:

{printf("Enter the element to be added to rear: ");

scanf("%d",&element);

renqueue(element);

break;

}

case 2:fdequeue();break;

case 3:

{printf("Enter the element to be added to front: ");

scanf("%d",&element);

fenqueue(element);

break;

}

case 4:rdequeue();break;

case 5:display();break;

case 6:return ;

}

}while(choice!=4);

}