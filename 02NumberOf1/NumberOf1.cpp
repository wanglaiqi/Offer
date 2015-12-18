#include<stdio.h>
#include<iostream>

using namespace std;

/*
 * 输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
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
解题思路如下：
（1）针对本题首先考虑正整数，如果该正整数能够整除2则说明该位为零，否则就为1，这样就可以计算出1的个数《--》Count1();
（2）由于除法效率比较低，因此我们采用函数Count2（），让该整数与1做&运算，就可以判断整数的最低位是否为1，然后将该整数
依次右移，移位操作比除法效率高很多，但是该方法遇到负数就会出现死循环，因为要保证移位后还为负数，因此改用方法三
（3）为了避免死循环的发生，我们就不右移输入的数字了，我们首先让该数与1进行&操作，看最低位是否是1，接着把1左移一位得2
，再和该数做与运算，就可以判断该数的次高位是否为1，这样反复，每次都可以判断a的其中一位是否是1.
（4）另外一种思路是如果一个整数不为0，那么这个整数至少有一位是1。如果我们把这个整数减去1，那么原来处在整数最右边的1就会变成0，
原来在1后面的所有的0都会变成1。其余的所有位将不受到影响。举个例子：一个二进制数1100，从右边数起的第三位是处于最右边的一个1。
减去1后，第三位变成0，它后面的两位0变成1，而前面的1保持不变，因此得到结果是1011。
我们发现减1的结果是把从最右边一个1开始的所有位都取反了。这个时候如果我们再把原来的整数和减去1之后的结果做与运算，
从原来整数最右边一个1那一位开始所有位都会变成0。如1100&1011=1000。也就是说，把一个整数减去1，再和原整数做与运算，
会把该整数最右边一个1变成0。那么一个整数的二进制有多少个1，就可以进行多少次这样的操作。
*/