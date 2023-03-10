#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};
struct Stack* createstack(unsigned capacity)
{
struct Stack* stack=(struct Stack*) malloc(sizeof(struct Stack));
if(!stack) return NULL;
stack->top=-1;
stack->capacity=capacity;
stack->array=(int *) malloc(stack->capacity*sizeof(int));
if(!stack->array) return NULL;
return stack;
}

int isEmpty(struct Stack* stack)
{
    if(stack->top==-1)
    return 1;
    else return 0;
}
int peek(struct Stack* stack)
{
    return stack->array[stack->top];
}
int pop(struct Stack* stack)
{    
    if(!isEmpty(stack))
    return stack->array[stack->top--];
    return 0;
}
void push(struct Stack* stack,int op)
{
    stack->array[++stack->top]=op;
}

int evaluatepostfix(char *exp)
{
   struct Stack* stack = createstack(strlen(exp));
   int i;
   if (!stack) return -1;
   //to check whether the stack is created
   for(i=0;exp[i];i++)
   {
    if(isdigit(exp[i]))
       push(stack,exp[i]-'0');

   else{
    int val1=pop(stack);
    int val2=pop(stack);

    switch(exp[i])
    {
       case '+':push(stack,val1+val2);break;         
       case '-':push(stack,val2-val1);break;
       case  '*':push(stack,val2*val1);break; 
       case  '/':push(stack,val2/val1);break;
       case '^':push(stack,pow(val2,val1));break;
    }
   }

   }
return pop(stack);
}

void main()
{
  char expression[100];
  printf("Enter the expression: ");
  scanf("%s",expression);
  printf("The value of the expreesion: %d",evaluatepostfix(expression));
}

