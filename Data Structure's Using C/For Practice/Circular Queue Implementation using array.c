#include<stdio.h>
#define CAPACITY 7
int queue[CAPACITY];
int front=-1,rear=-1;

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
void dequeue()
{
    if(front==-1&&rear==-1)
    {
        printf("Queue is Underflow\n");
    }
    else if(front==rear)
    {
        printf("%d Dequeued from Queue\n",queue[front]);
        front=rear=-1;
    }
    else if(front==CAPACITY-1)
    {
        printf("%d Dequeue from Queue\n",queue[front]);
        front=0;
    }
    else
    {
        printf("%d Dequeued from Queue\n",queue[front]);
        front++;
    }
}
void enqueue()
{
    if((front==rear+1)||((rear==CAPACITY-1)&&(front==0)))
    {
        printf("Queue is Overflow\n");
    }
    else if(front==-1&&rear==-1)
    {
        front=rear=0;
        int ele;
        printf("Enter Element\n");
        scanf("%d",&ele);
        queue[rear]=ele;
    }
    else if(rear==CAPACITY-1&&front>0)
    {
        rear=0;
        int ele;
        printf("Enter Element\n");
        scanf("%d",&ele);
        queue[rear]=ele;
    }
    else
    {
        rear++;
        int ele;
        printf("Enter Element\n");
        scanf("%d",&ele);
        queue[rear]=ele;
    }
}
void display()
{
    if(front==-1&&rear==-1)
    {
        printf("Queue is Underflow");
    }
    else if(front>rear)
    {
        int i;
        printf("Queue Elements are\n");
        for(i=front;i<CAPACITY;i++)
            printf("%d-->",queue[i]);
        for(i=0;i<=rear;i++)
            printf("%d-->",queue[i]);
    }
    else
    {
        int i;
        printf("Queue Elements are\n");
        for(i=front;i<=rear;i++)
            printf("%d-->",queue[i]);
    }
}
