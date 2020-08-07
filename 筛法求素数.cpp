#include<stdio.h>
int main()
{
	int i,j,m;//定义两个变量，i是从2到m的数字，j是用来被i除，检验i是否是素数的数,m是筛选范围
	scanf("%d",&m); 
	for(i=2;i<=m;i++)//i从2到m，挨个枚举，用下面的算法检验
	{
		for(j=2;j<i;j++)//j从2到i-1，用i除以j
		{
			if(i%j==0)//如果i除以j的余数是0，即i不是素数
			{
				break;//跳出循环
			}
			if(j==i-1)//如果直到j=i-1时上面的判断一直没成立，即i不是素数，输出i
			{
				printf("%d ",i);
			}
		}
	}
	return 0;
}
