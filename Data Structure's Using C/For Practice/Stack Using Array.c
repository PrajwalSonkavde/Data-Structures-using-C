#include<stdio.h>
#define CAPACITY 5
int stack[CAPACITY];
int top=-1;

void push();
void pop();
void peek();
int lenght();
void traverse();
int isfull();
int isempty();

void main()
{
    int ch;




    while(1)
    {
        printf("\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Traverse\n");
        printf("4.lenght\n");
        printf("5.Peek\n");
        printf("6.Quit\n");

        printf("Enter Your Choice : \n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1 : push();
                     break;
            case 2 : pop();
                     break;
            case 3 : traverse();
                     break;
            case 4 : printf("Lenght is %d\n",lenght());
                     break;
            case 5 : peek();
                     break;
            case 6 : exit(0);
            default : printf("Invalid Option\n");
        }
    }
}
void push()
{
    int item;
    if(isfull())
    {
        printf("Stack is Overflow\n");
    }
    else
    {
        top++;
        printf("Enter the element : \n");
        scanf("%d",&item);
        stack[top]=item;
        printf("%d pushed\n",stack[top]);
    }
}
void pop()
{
    if(isempty())
    {
        printf("Stack is Underflow\n");
    }
    else
    {
        printf("%d poped\n",stack[top]);
        top--;
    }
}
void peek()
{
    if(isempty())
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Peek Element is %d\n",stack[top]);
    }
}
int lenght()
{
    int count=0;
    if(isempty())
    {
        printf("Stack is Empty\n");
        return 0;
    }
    else
    {
        int i;
        for(i=0;i<=top;i++)
        {
            count++;
        }
        return count;
    }
}
void traverse()
{
    if(isempty())
    {
        printf("Stack is Empty\n");
    }
    else
    {
        int len;
        len=lenght();
        for(int i=0;i<=lenght()-1;i++)
        {
            printf("At Location %d = %d\n",i+1,stack[i]);
        }
    }
}
int isfull()
{
    if(top==CAPACITY-1)
        return 1;
    else
        return 0;
}
int isempty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
