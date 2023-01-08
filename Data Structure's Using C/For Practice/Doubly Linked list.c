#include<stdio.h>
#include<stdlib.h>
void append(void);
void display(void);
void addatbegin(void);
void addatafter(void);
void deleting(void);
int lenght(void);

struct node
{
    struct node* prev;
    int data;
    struct node *next;
};
struct node *head=NULL;

void main()
{
    int ch;

    while(1)
    {
        printf("1.Append\n");
        printf("2.AddAtBegin\n");
        printf("3.AddAtAfter\n");
        printf("4.Delete\n");
        printf("5.Display\n");
        printf("6.Length\n");
        printf("7.Quit\n");
        printf("8)Delete at Begining\n");

        printf("Enter your Choice\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: append();
                    break;
            case 2: addatbegin();
                    break;
            case 3: addatafter();
                    break;
            case 4: deleting();
                    break;
            case 5: display();
                    break;
            case 6: printf("Lenght is %d",lenght());
                    break;
            case 7: exit(0);
                    break;
            case 8 : delete_at_begining();
                    break;
            default: printf("Invalid Option\n");
        }
        printf("\n\n");
    }
}
void deleting()
{
    int loc,i=1;
    struct node*p=head,*temp=head;
    printf("Enter Location at which you want to delete\n");
    scanf("%d",&loc);
    if(loc>lenght())
    {
        printf("Currently list is %d nodes\n",lenght());
        printf("Invalid Location\n");
    }
    else
    {
        while(i<loc)
        {
            temp=temp->next;
            i++;
        }
        if(loc==1)
        {
           struct node*p;
           printf("At Location %d , %d Deleted\n",loc,temp->data);
           if(temp->prev==NULL)
           {
                free(temp);
                head=NULL;
           }
           else
           {
                p=temp->next;
                p->prev=NULL;
                head=p;
                temp->next=NULL;
                temp->prev=NULL;
                free(temp);
           }
        }
        else if(temp->next==NULL)
        {
            struct node*q;
            printf("At Location %d ,%d Deleted\n",loc,temp->data);
            /*if(temp->prev==NULL)
            {
                free(temp);
                head=NULL;
            }*/


                q=temp->prev;
                q->next=NULL;
                temp->prev=NULL;
                free(temp);

        }
        else
        {
            struct node*q;
            int i=1;
            while(i<loc)
            {
                p=p->next;
                i++;
            }
            printf("At Location %d ,%d Deleted\n",loc,p->data);
            q=p->prev;
            q->next=p->next;
            p->next->prev=q;
            p->next=NULL;
            p->prev=NULL;
            free(p);
        }
    }
}
int lenght()
{
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct node*p;
        p=head;
        int count=0;
        while(p!=NULL)
        {
            count++;
            p=p->next;
        }
        return count;
    }
}
void addatafter()
{
    int loc;

    printf("Enter Location after which you want to add\n");
    scanf("%d",&loc);
    if(loc>lenght())
    {
        printf("Currently list is %d nodes\n",lenght());
        printf("Invalid Location\n");
    }
    else
    {
        struct node*temp;
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter data\n");
        scanf("%d",&temp->data);
        temp->prev=NULL;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
        }
        else
        {
            struct node*p;
            p=head;
            int i=1;
            while(i<loc)
            {
                p=p->next;
                i++;
            }
            temp->next=p->next;
            temp->prev=p;
            p->next=temp;
        }
    }
}
void addatbegin()
{
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter data\n");
    scanf("%d",&temp->data);
    temp->next=NULL;
    temp->prev=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        struct node*p;
        p=head;
        temp->next=p;
        p->prev=temp;
        head=temp;
    }
}
void append()
{
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter data\n");
    scanf("%d",&temp->data);
    temp->prev=NULL;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        struct node*p;
        p=head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        temp->prev=p;
        p->next=temp;
    }
}
void display()
{
    if(head==NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        int c;
        printf("1.Display From Front\n");
        printf("2.Display From Last\n");

        printf("Enter Your Choice\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1: {
                    struct node*p;
                    p=head;
                    while(p!=NULL)
                    {
                        printf("%d-->",p->data);
                        p=p->next;
                    }
                    printf("\n\n");
                    }
                    break;
            case 2: {
                    struct node*p=head;
                    while(p->next!=NULL)
                    {
                        p=p->next;
                    }
                    while(p!=NULL)
                    {
                        printf("%d-->",p->data);
                            p=p->prev;
                    }
                    printf("\n\n");
                    }
                    break;
            default: printf("Invalid Option\n");
        }
    }
}
void delete_at_begining()
{
    if(head==NULL)
        printf("List is Empty");
    else
    {
        struct node * temp=head;

        if(temp->next==NULL)
        {
            printf("\n%d deleted\n",temp->data);
            head=NULL;
        }
        else
        {
            printf("\n%d deleted\n",temp->data);
            temp->next->prev=NULL;
            head=temp->next;
            temp->prev=NULL;
            temp->next=NULL;
            free(temp);
        }

    }
}
