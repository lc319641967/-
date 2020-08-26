#include<stdio.h>
#include<stdlib.h>
 
 
int GetDuplication(int arr[], int len)
{
	//处理异常情况
	if (arr == NULL || len <= 0)
	{
		return -1;
	}
	//限定范围
	for (int i=0;i<len;i++)
	{
		if (arr[i] < 0 || arr[i] >= len)
		{
			return -2;
		}
	}
	//查找
	for (i = 0; i < len; i++)//遍历整个数组
	{
		while (arr[i] != i)//当数组元素不等于下标时才执行循环
		{
			if (arr[i] == arr[arr[i]])//找到重复数
			{
				return arr[i];
			}
			else
			{
				//交换
				int tmp = arr[i];
				arr[i] = arr[tmp];
				arr[tmp] = tmp;
			}
		}
	}
	return -3;
}
 
int main()
{
	int arr[] = { 1, 3, 2, 0, 2, 5, 3 };
	int len = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < len; i++)
	{
		printf("% d", arr[i]);
	}
	printf("\n");
	int ret = GetDuplication(arr, len);
	printf("% d\n", ret);
	system("pause");
	return 0;
}