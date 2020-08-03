#include<stdio.h>
int main()
{
    int a,b;
    int c=0,d=0;
    scanf("%d%d",&a,&b);（输入两个数）
    if(a<b)
    {
    	d=a;
        a=b;
        b=d;
    }
    while(a%b)
    {
    	c=a%b;
    	a=b;
    	b=c;
    }
    printf("%d\n",b);
 }
