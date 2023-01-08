#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int data;
    struct node*link;
};
struct queue*front =NULL,*rear=NULL,*node=NULL;

void main()
{
    int ch;
    while(1)
    {
        printf("1.enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Quit\n");

        printf("Enter your choice\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: enqueue();
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("Invalid Option\n");
        }
        printf("\n\n");
    }
}
void enqueue()
{
    node=(struct node*)malloc(sizeof(struct queue));
    printf("Enter data\n");
    scanf("%d",&node->data);
    node->link=NULL;
    if(rear==NULL&&front==NULL)
    {
        rear=front=node;
    }
    else
    {
        front->link=node;
        front=node;
        front->link=rear;
    }
}
void dequeue()
{
    if(rear==NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        node=front;
        printf("Value %d dequeued from Queue\n",node->data);
        if(rear->link==rear||rear->link==NULL)
        {
            rear=front=NULL;
        }
        else
        {
            while(node->link!=front)
        {
            node=node->link;
        }
        node->link=rear;
        front=node;
        }
    }
}
void display()
{
    if(front==NULL&&rear==NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        node = rear;
        printf("List of data into the Queue : \n");
        printf("%d-->",node->data);
        while(node != front)
            {
                node = node->link;
                printf("%d-->",node->data);
            }
    }
}
