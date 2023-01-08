#include<stdio.h>
#define CAPACITY 7
int queue[CAPACITY];
int front=0,rear=0;

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
    if(rear==CAPACITY-1)
    {
        printf("Queue is Full\n");
    }
    else
    {
        int ele;
        printf("Enter Element\n");
        scanf("%d",&ele);
        queue[rear]=ele;
        rear++;
    }
}
void dequeue()
{
    if(front==rear)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        int i,ele;
        printf("%d dequeued from Queue\n",queue[front]);
        for(i=front;i<rear;i++)
        {
            queue[i]=queue[i+1];
        }
        rear--;
    }
}
void display()
{
    if(rear==front)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        int i;
        printf("Queue Elements are\n");
        for(i=front;i<rear;i++)
        {
            printf("%d-->",queue[i]);
        }
    }
}
