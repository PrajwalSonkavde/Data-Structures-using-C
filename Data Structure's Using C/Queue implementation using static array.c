#include<stdio.h>

#define CAPACITY 5
int queue[CAPACITY];
int front=0;
int rear=0;
void main()
{
    int ch;
    while(1)
 {
    printf("Queue Operations are\n");
    printf("1.Insert\n");
    printf("2.traverse\n");
    printf("3.delete\n");
    printf("4.quit\n");

    printf("Enter your Choice\n");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1: insert();
                break;
        case 2: traverse();
                break;
        case 3: deleting();
                break;
        case 4: exit(0);

        default: printf("Invalid Option\n");
    }
 }
}
void insert()
{
    if(CAPACITY==rear)
        printf("Queue is Full\n");
    else
    {
        int ele;
        printf("Enter the element\n");
        scanf("%d",&ele);

        queue[rear]=ele;
        rear++;
    }
}
void deleting()
{
    if(front==rear)
        printf("Queue is Empty\n");
    else
        {
            printf("%d Deleled Element\n",queue[front]);
            for(int i=0;i<rear;i++)
            {
                queue[i]=queue[i+1];
            }
            rear--;
        }
}
void traverse()
{
    if(front==rear)
        printf("Queue is Empty\n");
    else
    {
        printf("Queue Elements are\n");
        for(int i=0;i<rear;i++)
        {
            printf("%d\n",queue[i]);
        }
    }
}
