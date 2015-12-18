#include<stdio.h>
#include<iostream>

using namespace std;

/*
 * ����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��
*/
class Solution
{
public:
	int NumberOf1(int n);
	int Count1(int n);
	int Count2(int n);
	int Count3(int n);
	int Count4(int n);
	Solution();
	~Solution();

private:

};

int Solution::NumberOf1(int n)
{
	return 0;
}

int Solution::Count1(int n)
{
	int number = 0;
	while (n)
	{
		if (n%2==1)
		{
			number++;
		}
		n /= 2;
	}
	return number;
}

int Solution::Count2(int n)
{
	int num = 0;
	while (n)
	{
		if ((n&1)==1)
		{
			num++;
		}
		n >>= 2;
	}
	return num;
}

int Solution::Count3(int n)
{
	int num = 0;
	while (n)
	{
		++num;
		n = (n - 1)&n;
	}
	return num;
}

int Solution::Count4(int n)
{
	int num = 0;
	unsigned int flag = 1;
	while (flag)
	{
		if (n&1)
		{
			num++;
		}
		flag = flag << 1;
	}
	return num;
}

Solution::Solution()
{
}

Solution::~Solution()
{
}

int main()
{
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	int count4 = 0;
	Solution s;
	count1 = s.Count1(5);
	count2 = s.Count2(5);
	count3 = s.Count3(5);
	//count4 = s.Count4(5);
	cout << count1 << endl;
	cout << count2 << endl;
	cout << count3 << endl;
	cout << count4 << endl;
	system("pause");
	return 0;
}
/*
����˼·���£�
��1����Ա������ȿ�����������������������ܹ�����2��˵����λΪ�㣬�����Ϊ1�������Ϳ��Լ����1�ĸ�����--��Count1();
��2�����ڳ���Ч�ʱȽϵͣ�������ǲ��ú���Count2�������ø�������1��&���㣬�Ϳ����ж����������λ�Ƿ�Ϊ1��Ȼ�󽫸�����
�������ƣ���λ�����ȳ���Ч�ʸߺܶ࣬���Ǹ÷������������ͻ������ѭ������ΪҪ��֤��λ��Ϊ��������˸��÷�����
��3��Ϊ�˱�����ѭ���ķ��������ǾͲ���������������ˣ����������ø�����1����&�����������λ�Ƿ���1�����Ű�1����һλ��2
���ٺ͸����������㣬�Ϳ����жϸ����Ĵθ�λ�Ƿ�Ϊ1������������ÿ�ζ������ж�a������һλ�Ƿ���1.
��4������һ��˼·�����һ��������Ϊ0����ô�������������һλ��1��������ǰ����������ȥ1����ôԭ�������������ұߵ�1�ͻ���0��
ԭ����1��������е�0������1�����������λ�����ܵ�Ӱ�졣�ٸ����ӣ�һ����������1100�����ұ�����ĵ���λ�Ǵ������ұߵ�һ��1��
��ȥ1�󣬵���λ���0�����������λ0���1����ǰ���1���ֲ��䣬��˵õ������1011��
���Ƿ��ּ�1�Ľ���ǰѴ����ұ�һ��1��ʼ������λ��ȡ���ˡ����ʱ����������ٰ�ԭ���������ͼ�ȥ1֮��Ľ���������㣬
��ԭ���������ұ�һ��1��һλ��ʼ����λ������0����1100&1011=1000��Ҳ����˵����һ��������ȥ1���ٺ�ԭ�����������㣬
��Ѹ��������ұ�һ��1���0����ôһ�������Ķ������ж��ٸ�1���Ϳ��Խ��ж��ٴ������Ĳ�����
*/