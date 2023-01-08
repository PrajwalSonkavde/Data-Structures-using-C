#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* link;
};
struct node*front=NULL;
struct node*rear=NULL;
void main()
{
    int ch;
    while(1)
 {
    printf("Queue Operations are\n");
    printf("1.Enqueue\n");
    printf("2.Display\n");
    printf("3.Dequeue\n");
    printf("4.Lenght\n");
    printf("5.Quit\n");

    printf("Enter your Choice\n");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1: enqueue();
                break;
        case 2: display();
                break;
        case 3: dequeue();
                break;
        case 4: printf("Lenght is %d",lenght());
                break;
        case 5: exit(0);
        default: printf("Invalid Option\n");
    }
    printf("\n\n");
 }
}
void enqueue()
{
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter data\n");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(rear==NULL)
    {
        rear=front=temp;
    }
    else
    {
        rear->link=temp;
        rear=temp;
    }
}
void display()
{
    if(rear==NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        struct node*p=front;
        while(p!=NULL)
        {
            printf("%d-->",p->data);
            p=p->link;
        }
    }
}

void dequeue()
{
    struct node*temp;
    temp=front;
    if(rear==NULL)
    {
        printf("Queue is Empty\n");
    }
    else if(temp->link==NULL)
    {
        printf("%d Dequeued from Queue\n",temp->data);
        rear=NULL;
        front=NULL;
    }
    else
    {
        printf("%d Dequeued from Queue\n",temp->data);
        front=temp->link;
        temp->link=NULL;
        free(temp);
    }
}
int lenght()
{
    if(rear==NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        struct node*p=front;
        int count=0;
        while(p!=NULL)
        {
            count++;
            p=p->link;
        }
        return count;
    }
}

