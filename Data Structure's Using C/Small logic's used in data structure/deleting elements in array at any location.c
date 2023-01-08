#include<stdio.h>

void main()
{
    int stack[8]={1,2,3,4,5,6},i;
    int loc=2,temp=5;
     for(i=0;i<=temp;i++)
        printf("%d\n",stack[i]);
    for(i=loc-1;i<=temp;i++)
    {
        stack[i]=stack[i+1];
    }
    printf("\n\n");
    temp--;
    for(i=0;i<=temp;i++)
        printf("%d\n",stack[i]);
}
