#include<stdio.h> 
#include<math.h> 
int main()
{
	float a,b,c,p,area; 
	printf("�����������ε����߳�\n"); 
	scanf("%f %f %f",&a,&b,&c); 
	p=1.0/2*(a+b+c);  
	if(a+b>c&&b+c>a&&a+c>b)
	{   
		area=sqrt(p*(p-a)*(p-b)*(p-c)); 
		printf("�����ε����Ϊ��%7.2f\n",area); 
	} 
	else 
		printf("���ܹ���������\n");
	return 0;
}