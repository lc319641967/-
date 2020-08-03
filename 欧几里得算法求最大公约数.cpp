#include<stdio.h>
int main()
{
    int a,b;
    int c=0,d=0;
    scanf("%d%d",&a,&b);（输入两个数）
    if(a<b)（比较大小，交换位置）
    {
    	d=a;
        a=b;
        b=d;
    }
    while(a%b)（辗转相除法）
    {
    	c=a%b;
    	a=b;
    	b=c;
    }
    printf("%d\n",b);
 }
