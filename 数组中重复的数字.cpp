#include<stdio.h>
#include<stdlib.h>
 
 
int GetDuplication(int arr[], int len)
{
	//�����쳣���
	if (arr == NULL || len <= 0)
	{
		return -1;
	}
	//�޶���Χ
	for (int i=0;i<len;i++)
	{
		if (arr[i] < 0 || arr[i] >= len)
		{
			return -2;
		}
	}
	//����
	for (i = 0; i < len; i++)//������������
	{
		while (arr[i] != i)//������Ԫ�ز������±�ʱ��ִ��ѭ��
		{
			if (arr[i] == arr[arr[i]])//�ҵ��ظ���
			{
				return arr[i];
			}
			else
			{
				//����
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