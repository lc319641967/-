#include<stdio.h>
void exGcd(int a,int b,int *x,int *y)       //扩展欧几里得(求出x0,y0）  
{
    int t;
    if(b == 0)
    {
        *x = 1;
        *y = 0;
        return ;
    }
    exGcd(b,a%b,x,y);
    t = *x;
    *x = *y;
    *y = t-a/b*(*y);
}

int main()
{
    int a,b;
    int x,y;
    scanf("%d%d",&a,&b);
    exGcd(a,b,&x,&y);
    while(x < 0) x += b;            		//根据通解公式进行累加,找到最小正整数
    printf("%d\n",x);
    return 0;
}