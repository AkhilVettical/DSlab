#include<stdio.h>
#include<limits.h>
int stack[100],choice,size,top=-1,value,i,delete;
void push(int x);
int pop();
void display();
void main()
{
printf("Enter the size of the stack: ");
scanf("%d",&size);
printf("1-PUSH\n2-POP\n3-DISPLAY\n4-EXIT\n");
do{
printf("Enter the choice: ");
scanf("%d",&choice);
switch(choice)
{
    case 1:
    {
        printf("Enter the element to be pushed: ");
        scanf("%d",&value);
        push(value);
        break;
    }
    case 2:
    {
        delete=pop();
        printf("The deleted element is: %d",delete);
        break;
    }
    case 3:
    {
    display();
    break;
    }
    case 4:
    {
    break;
    }
}
}while(choice!=4);

}
void push(int x)
{   
    if(top>(size-1))
    {
    printf("STACK OVERFLOW\n");
    }
    else
    {
    top++;
    stack[top]=x;
    }
    

}
int pop()
{
    if(top==-1)
    {
    printf("STACK UNDERFLOW\n");
    return INT_MIN;
    }
    return stack[top];
    top--;
}

void display()
{
    for(i=top;i>=0;i--)
    printf("%d\n",stack[i]);
}