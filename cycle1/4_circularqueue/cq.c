#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int front=-1,rear=-1,maxsize;
int *cqueue;
void enqueue(int x)
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
void dequeue()
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
    {for(i=front;i<=maxsize-1;i++)
    printf("%d ",cqueue[i]);
    for(i=0;i<=rear;i++)
    printf("%d ",cqueue[i]);
    }
    printf("\n");
    }
}
void main()
{   int choice,element;
    printf("Enter the maxsize of the queue: ");
    scanf("%d",&maxsize);
    cqueue= (int*) malloc(maxsize*sizeof(int));
        printf("1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n");
    do{
    printf("Enter the choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
     case 1:{printf("Enter the element to be added: ");
            scanf("%d",&element);
            enqueue(element);
            break;}
     case 2:dequeue();break;
     case 3:display();break;
     case 4:return ;
    }
    }while(choice!=4);
}