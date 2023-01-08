#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *top=NULL;

void push();
//void pop();
//void peek();
int lenght();
void traverse();

void main()
{
    int ch;
    while(1)
    {
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
        printf("\n");
    }
}
void push()
{
    struct node *t;
    t=(struct node*)malloc(sizeof(struct node));
    t->link=NULL;
    printf("Enter data : \n");
    scanf("%d",&t->data);
    t->link=NULL;
    if(top!=NULL)
    {
        t->link=top;
    }
    top=t;
    printf("%d Pushed\n",t->data);
}
void pop()
{
    if(top==NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        struct node*temp;
        temp=top;
        printf("%d Poped\n",temp->data);
        top=temp->link;
        temp->link=NULL;
        free(temp);
    }
}
void peek()
{
    if(top==NULL)
        printf("Stack is Empty\n");
    else
    {
        struct node *t;
        t=top;
        printf("Peek Element is %d\n",t->data);
    }
}
void traverse()
{
    if(top==NULL)
        printf("Stack is Emmpty\n");
    else
    {
        struct node *p;
        p=top;
        for(int i=0;p!=NULL;i++)
        {
            printf("At Location %d = %d\n",i+1,p->data);
            p=p->link;
        }
    }
}
int lenght()
{
    if(top==NULL)
        printf("Stack is Emmpty\n");
    else
    {
        struct node *p;
        p=top;
        int count;
        for(int i=0;p!=NULL;i++)
        {
            count++;
            p=p->link;
        }
        return count;
    }
}
