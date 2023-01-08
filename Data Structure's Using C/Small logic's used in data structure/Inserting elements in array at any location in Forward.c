#include<stdio.h>

void main()
{
    int stack[8]={1,2,3,4,5,6},i;
    int loc=2,temp=5;
     for(i=0;i<=temp;i++)
        printf("%d\n",stack[i]);
    for(i=temp+1;i>loc;i--)
    {
        stack[i]=stack[i-1];
    }
    stack[loc]=1000;
    printf("\n\n");
    temp++;
    for(i=0;i<=temp;i++)
        printf("%d\n",stack[i]);
}
