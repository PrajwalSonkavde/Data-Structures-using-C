#include<stdio.h>

void main()
{
    int stack[8]={1,2,3,4,5,6},i,temp=6;
    for(i=0;i<=5;i++)
        printf("%d\n",stack[i]);
    for(i=temp+1;i!=NULL;i--)
    {
        stack[i]=stack[i-1];
    }
    printf("\n\n");
    for(i=0;i<=temp;i++)
        printf("%d\n",stack[i]);
}
