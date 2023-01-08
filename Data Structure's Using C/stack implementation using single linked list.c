#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node* top=NULL;

void main()
{
      int ch;

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
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: peek();
                    break;
            case 4: traverse();
                    break;
            case 5: exit(0);
        }
}
}
void push()
{
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d",&temp->data);
    temp->link=top;
    top=temp;
}
void pop()
{
    struct node * temp;
    temp=top;
    if(temp==NULL)
        printf("Stack is Empty\n");
    else
    {
        temp=top;
        printf("%d Element removed\n",temp->data);
        top=temp->link;
        temp->link=NULL;
        free(temp);
    }
}
void traverse()
{
    struct node*temp;
    temp=top;
    if(temp==NULL)
        printf("Stack is Empty\n");
    else
    {
        printf("Elements are :\n");
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->link;
        }
    }
}
void peek()
{
    struct node*temp;
    temp=top;
    if(temp==NULL)
        printf("Stack is Empty\n");
    else
        printf("Peek Element is %d\n",temp->data);
}
