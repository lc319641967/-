/*ʵ��?int sqrt(int x)?������

���㲢����?x?��ƽ����������?x �ǷǸ�������

���ڷ������������������ֻ���������Ĳ��֣�С�����ֽ�����ȥ��

ʾ�� 1:

����: 4
���: 2
ʾ�� 2:

����: 8
���: 2
˵��: 8 ��ƽ������ 2.82842..., 
?    ���ڷ���������������С�����ֽ�����ȥ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/sqrtx
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������*/
int mySqrt(int x){
    int left=1,right=x/2;
    int mid=(left+right)/2;
    while(left<right)
    {
        if(mid*mid==x)
        return mid;
        else if(mid*mid<x)
        left=mid+1;
        else
        right=mid+1;
        mid=(left+right)/2;
    }
        if(left*left>x)
        return left-1;
        return left;
}