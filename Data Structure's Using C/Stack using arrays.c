#include<stdio.h>
#define CAPACITY 5
int stack[CAPACITY],top=-1;
void push(int ele);
int pop(void);
void peek(void);
void Traverse(void);

void main()
{
    int ch,item;

    while(1)
    {
        printf("1.Push \n");
        printf("2.Pop \n");
        printf("3.Peek\n");
        printf("4.Traverse\n");
        printf("5.Quit\n");

        printf("Enter Your Choice\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1 : printf("Enter element \n");
                     scanf("%d",&item);
                     push(item);
                     printf("\n\n");
                     break;
            case 2 : item=pop();
                     if(item==0)
                     {
                         printf("Stack is Underflow\n");
                     }
                     else
                     {
                         printf("%d has poped\n",item);
                     }
                     printf("\n\n");
                     break;
            case 3 : peek();
                     printf("\n\n");
                     break;
            case 4 : traverse();
                     printf("\n\n");
                     break;
            case 5 : exit(0);

        }
    }
}
void push(int ele)
{
    if(isFull())
    {
        printf("Stack is Overflow\nCan't Add Element\n");
    }
    else
    {
        top++;
        stack[top]=ele;
        printf("%d pushed\n",ele);
    }
}
int isFull()
{
    if(top==(CAPACITY-1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int pop()
{
    if(isEmpty())
    {
        return 0;
    }
    else
    {
        return stack[top--];
    }
}
int isEmpty()
{
    if(top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void peek()
{
    if(isEmpty())
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Peek Element : %d\n",stack[top]);
    }
}
void traverse()
{
    if(isEmpty())
    {
        printf("Stack is Empty\n");
    }
    else
    {
        int i;
        printf("Stack Element are : \n");
        for(i=0;i<=top;i++)
        {
            printf("%d\n",stack[i]);
        }
    }
}
