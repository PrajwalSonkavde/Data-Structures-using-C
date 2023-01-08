#include<stdio.h>
#include<stdlib.h>

void append(void);
void addatbegin(void);
void addatafter(void);
int lenght(void);
void traverse(void);
void deleting(void);
void reversing(void);
void nodeswap(void);

struct node
{
    int data;
    struct node*link;
};
struct node *root=NULL;
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
        printf("7.reverse elements\n");
        printf("8.Node swap\n");
        printf("9.Quit\n");

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
            case 4: if(lenght()!=NULL)
                    {
                        printf("Lenght %d\n",lenght());
                    }
                    else
                    {
                        printf("List is Empty\n");
                    }
                    break;
            case 5: traverse();
                    break;
            case 6: deleting();
                    break;
            case 7: reversing();
                    break;
            case 8: nodeswap();
                    break;
            case 9: exit(0);
            default: printf("Invalid Option\n");
        }
        printf("\n\n");
    }
}
void nodeswap()
{
    struct node *temp=root;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->link;
    }
    if(root==NULL)
    {
        printf("List is Empty\n");
    }
    else if(count<2)
    {
        printf("Currently You have %d nodes\n",count);
        printf("To Swap Nodes you must have Atleast 4 Nodes\n");
    }
    else
    {
        free(temp);
        int i,loc;
        printf("Enter Location\n");
        scanf("%d",&loc);
        if(loc==1||loc==2)
        {
            struct node*p=root,*q;
            q=p->link;
            p->link=q->link;
            q->link=p;
            root=q;

        }
        else
        {
        struct node*p=root,*q,*r;
        while(i<loc-1)
        {
            p=p->link;
            i++;
        }
        q=p->link;
        r=q->link;

        q->link=r->link;
        r->link=q;
        p->link=r;
        }
    }
}
void reversing()
{
    int i,j,len;
    len=lenght();
    i=0;
    j=len-1;
    struct node *p,*q;
    p=q=root;
    while(i<j)
    {
        int k=0;
        while(k<j)
        {
            q=q->link;
            k++;
        }
        int temp;
        temp=p->data;
        p->data=q->data;
        q->data=temp;
        i++;
        j--;
        p=p->link;
        q=root;
    }
    printf("Data Reversed\n");
}
void append()
{
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter Data\n");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        struct node* p;
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
    struct node*t;
    t=(struct node*)malloc(sizeof(struct node));
    printf("Enter Data\n");
    scanf("%d",&t->data);
    t->link=NULL;
    if(root==NULL)
    {
        root=t;
    }
    else
    {
        struct node*p;
        p=root;
        t->link=p;
        root=t;
    }
}
void addatafter()
{
    int loc;
    printf("Enter at location you want to Enter\n");
    scanf("%d",&loc);
    if(loc>lenght())
    {
        printf("Invalid Location\n");
        printf("Currently list is having %d nodes",lenght());
    }
    else
    {
        struct node* t;
        t=(struct node*)malloc(sizeof(struct node));
        struct node*p;
        int i=1;
        p=root;
        while(i<loc)
        {
            p=p->link;
            i++;
        }
        printf("Enter data\n");
        scanf("%d",&t->data);
        t->link=p->link;
        p->link=t;
    }
}
int lenght()
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        struct node*p;
        p=root;
        int count=0;
        while(p!=NULL)
        {
            count++;
            p=p->link;
        }
        return count;
    }
}
void traverse()
{
    if(root==NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        struct node*p;
        p=root;
        printf("List Elements are\n");
        for(int i=1;p!=NULL;i++)
        {
            printf("At Location %d = %d\n",i,p->data);
            p=p->link;
        }
    }
}
void deleting()
{
    int loc;
    printf("Enter Location uh want to delete Element\n");
    scanf("%d",&loc);
    if(loc>lenght())
    {
        printf("Currently List is having %d nodes\n",lenght());
        printf("Invalid Location\n");
    }
    else if(loc==1)
    {
        struct node*p;
        p=root;
        printf("At Location %d , %d deleted\n",1,p->data);
        root=p->link;
        p->link=NULL;
        free(p);
    }
    else
    {
        struct node*p,*q;
        p=root;
        int i=1;
        while(i<loc-1)
        {
            p=p->link;
            i++;
        }
        q=p->link;
        printf("At Location %d , %d deleted\n",i+1,q->data);
        p->link=q->link;
        q->link=NULL;
        free(q);
    }
}
