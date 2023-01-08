#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node* root =NULL;
int len;
void append(void);
void addatbegin(void);
void addatafter(void);
int lenght(void);
void display(void);
void deleting(void);
void main()
{
    int ch;
    while(1)
    {
        printf("Single linked list operations : \n");
        printf("1.Append\n");
        printf("2.Add At Begin\n");
        printf("3.Add At After\n");
        printf("4.Lenght\n");
        printf("5.Display\n");
        printf("6.Delete\n");
        printf("7.Quit\n");

        printf("Enter Your Choice :\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1 : append();
                     break;
            case 2 : addatbegin();
                     break;
            case 3 : addatafter();
                     break;
            case 4 : len =lenght();
                     printf("Length is %d\n",len);
                     break;
            case 5 : display();
                     break;
            case 6 : deleting();
                     break;
            case 7 : exit(1);

            default : printf("Invalid Option\n");
        }
    }
}
void append()
{
    struct node * temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d",&temp->data);
    temp->link=NULL;

    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        struct node *p;
        p=root;
        while(p->link!=NULL)
        {
            p=p->link;
        }
        p->link=temp;
    }
}
void addatbegin()
{
    struct node * temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        struct node*p;
        p=root;
        temp->link=p;
        root=temp;
    }
}
void addatafter()
{
    struct node* temp, *p;
    temp =(struct node*)malloc(sizeof(struct node));
    int loc;
    printf("Enter the location\n");
    scanf("%d",&loc);
    len=lenght();
    if(loc > len)
    {
        printf("Invalid Choice\n");
        printf("Total lenght is %d\n",len);
    }
    else
    {
        p=root;
        int i=1;
        while(i<loc)
        {
            p=p->link;
            i++;
        }
        printf("Enter the data\n");
        scanf("%d",&temp->data);
        temp->link=p->link; //right
        p->link=temp; //left
    }
}
int lenght()
{
    struct node*p;
    int count=0;
    p=root;
    if(root==NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        while(p!=NULL)
        {
            count++;
            p=p->link;
        }
    }
    return count;
}
void display()
{
    struct node * temp;
    temp=root;
    if(temp==NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        printf("Elements are : \n");
        while(temp!=NULL)
        {
            printf("%d-->",temp->data);
            temp=temp->link;
        }
        printf("\n\n");
    }
}
void deleting()
{
    struct node * temp;
    temp=root;
    int loc;
    printf("Enter location you want to delete at\n");
    scanf("%d",&loc);

    if(loc > lenght())
    {
      printf("Invalid option\n");
    }
    else if(loc==1)
    {
        temp=root;
        root=temp->link;
        temp->link=NULL;
        free(temp);
    }
    else
    {
        struct node *p,*q;
        p=root;
        int i=1;
        while(i<loc-1)
        {
            p=p->link;
            i++;
        }
        q=p->link;
        p->link=q->link;
        q->link=NULL;
        free(q);
    }
}
