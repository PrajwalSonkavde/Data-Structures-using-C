

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
void enqueue()
{
    if ((front == 0 && rear == CAPACITY - 1) || (front == rear + 1))
    {
        printf("queue is full");
        return;
    }
    else if (rear ==  - 1)
    {
        rear++;
        front++;
        int ele;
        printf("Enter Element\n");
        scanf("%d",&ele);
        queue[rear]=ele;
    }
    else if (rear == CAPACITY - 1 && front > 0)
    {
        rear = 0;
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

void dequeue()
{
    if (front ==  - 1||rear==-1)
    {
        printf("Queue is empty ");
    }
    else if (front == rear)
    {
        printf("\n %d dequeued from Queue", queue[front]);
        front =  - 1;
        rear =  - 1;
    }
    else if(front==CAPACITY-1)
    {
        printf("\n%d dequeued from Queue",queue[front]);
        front=0;
    }
    else
    {
        printf("\n %d dequeued from Queue", queue[front]);
        front++;
    }
}

void display()
{
    int i;
    printf("\n");
    if(front==-1||rear==-1)
        printf("Queue is Empty\n");
    else if (front > rear)
    {
        for (i = front; i < CAPACITY; i++)
        {
            printf("%d-->", queue[i]);
        }
        for (i = 0; i <= rear; i++)
            printf("%d-->", queue[i]);
    }
    else
    {
        for (i = front; i <= rear; i++)
            printf("%d-->", queue[i]);
    }
}
