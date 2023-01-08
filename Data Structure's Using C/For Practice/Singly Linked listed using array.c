#include<stdio.h>
#define CAPACITY 7

void append(void);
void addatbegin(void);
void addatafter(void);
void lenght(void);
void traverse(void);
void deleting(void);

int stack[CAPACITY];
int temp=-1;

void main()
{
    int ch;
    while(1)
    {
        printf("Singly Linked List\n");
        printf("1.Append\n");
        printf("2.Addatbegin\n");
        printf("3.Addatafter\n");
        printf("4.Lenght\n");
        printf("5.Display\n");
        printf("6.Delete\n");
        printf("7.Quit\n");

        printf("Enter Your choice\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: append();
                    break;
            case 2: addatbegin();
                    break;
            case 3: addatafter();
                    break;
            case 4: lenght();
                    break;
            case 5: traverse();
                    break;
            case 6: deleting();
                    break;
            case 7: exit(0);
            default: printf("Invalid Option\n");
        }
        printf("\n\n");
}
}
void append()
{
    if(temp==CAPACITY-1)
    {
        printf("List is Full\n");
    }
    else
    {
        temp++;
        int ele;
        printf("Enter the data\n");
        scanf("%d",&ele);
        stack[temp]=ele;
    }
}
void addatbegin()
{
    if(temp==CAPACITY-1)
    {
        printf("List is Full\n");
    }
    else
    {
        if(temp==-1)
        {
            temp++;
            int ele;
            printf("Enter data\n");
            scanf("%d",&ele);
            stack[temp]=ele;
        }
        else
        {
            int ele,i;
            printf("Enter data\n");
            scanf("%d",&ele);
            for(i=temp+1;i!=NULL;i--)
            {
                stack[i]=stack[i-1];
            }
            stack[0]=ele;
            temp++;
        }
    }
}
void addatafter()
{
    int loc;
    printf("Enter Location at which you want to enter\n");
    scanf("%d",&loc);
    if(temp==CAPACITY-1)
    {
        printf("List is Full\n");
    }

    else if(temp==-1)
    {
        if(loc-1>temp+1)
        {
            if(temp==-1)
                printf("There are no nodes/data in list So Enter Location as 1 or 0 and Location assigned will be 1");
            else
            {
                printf("Currently List is having %d nodes\n",temp+1);
                printf("Invalid Option\n");
            }
        }
       else
        {
            temp++;
            int ele;
            printf("Enter data\n");
            scanf("%d",&ele);
            stack[temp]=ele;

        }
    }
    else
    {
          if(loc-1>temp)
       {
           printf("Currently List is having %d nodes\n",temp+1);
                printf("Invalid Option\n");
       }
          else
          {
        int i,ele;
        printf("Enter data\n");
        scanf("%d",&ele);
        for(i=temp+1;i>loc;i--)
        {
            stack[i]=stack[i-1];
        }
        stack[loc]=ele;
        temp++;
    }
    }
}
void traverse()
{
    if(temp==-1)
    {
        printf("List is Empty\n");
    }
    else
    {
        int i=0;
        while(i<=temp)
        {
            printf("At Location %d = %d\n",i+1,stack[i]);
            i++;
        }
    }
}
void deleting()
{
    if(temp==-1)
    {
        printf("List is Empty\n");
    }
    else
    {   int loc;
        printf("Enter Location at which you want to delete\n");
        scanf("%d",&loc);

        if(loc>temp+1)
        {
            printf("Currently List is having %d node\n",temp+1);
            printf("Invalid Location\n");
        }
        else
        {
            int i;
            printf("At Location %d , %d deleted\n",loc,stack[loc-1]);
            for(i=loc-1;i<=temp;i++)
            {
                stack[i]=stack[i+1];
            }
            temp--;
        }
    }
}
void lenght()
{
    if(temp==-1)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("Lenght is %d",temp+1);
    }
}
