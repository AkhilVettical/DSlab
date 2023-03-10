#include<stdio.h>
#include<stdlib.h>

int front=-1,rear=-1,maxsize;
int *queue;
void enqueue(int x)
{
    if(rear>=maxsize-1)
        {printf("QUEUE OVERFLOW\n");
        return;
        }
    rear++;
    queue[rear]=x;
}
void dequeue()
{
    if(front==rear)
    printf("QUEUE UNDERFLOW\n");
    else{
    front++;
    printf("The deleted element: %d\n",queue[front]);
    }
}
void display()
{
    int i;
    for(i=front+1;i<=rear;i++)
    printf("%d ",queue[i]);
    printf("\n");
}

void main()
{   int choice,element;
    printf("Enter the maxsize of the queue: ");
    scanf("%d",&maxsize);
    queue= (int*) malloc(maxsize*sizeof(int));
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