#include<stdio.h>
#define Max 100
 
//��׳�
int factorial_function(int num)
{
	if(num <= 1)
		return 1;
	else
		return (factorial_function(num-1)*num);
}
 
int main()
{
	int num[Max];
	char s[Max];
	int i=0,j=0,k=0,count=0;
	char val;
	int sum = 0;
 
	//***********************************************��ȡ���е�Ԫ�أ�A C B D   ���� 1324   ***************************************************************
	while(scanf("%c",&val))
	{
		if(val == '\n')
			break;
		else
		{
			s[count] = val;
			count ++;
		}
	}
 
	printf("count = %d\n",count);
 
	//**********************************�ֱ����Ԫ�ص��������һ��Ԫ����Ҫ��ʣ�µ�n-1���Ƚϣ�***********************************************************
	//**********************************�ڶ���Ԫ����Ҫ��ʣ�µ�n-2���Ƚϣ�������Ԫ����Ҫ��ʣ�µ�n-3��Ԫ�ؽ��бȽϵȵ�**************************************
	for(i=0;i<count;i++)
	{
		printf("*************************%c************************\n",s[i]);
		for(j=i+1;j<count;j++)
		{
			if(s[i]>s[j])
			{
				printf("%d: %c\t%c\n",j,s[i],s[j]);
				k ++;
			}
			
		}
		printf("%d\n",k);
		num[i] = k;
		k = 0;
	}
	//*************************************��������1324�ǵ���������*****************************************************
	for(j=count-1;j>=0;j--)
	{
		sum += factorial_function(j) * num[k];
		printf("%d:%d = %d*%d\n",k,sum,factorial_function(j),num[k]);
		k++;
	//	printf("%c",s[k++]);
	}
	printf("�ǵ�%d����\n",sum+1);
 
	return 0;
}
