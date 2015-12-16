#include<stdio.h>
#include<iostream>

using namespace std;
/*
请实现一个函数，把字符串中的每个空格替换成“%20”。
例如输入“We are happy.”，则输出“We%20are%20happy.
*/
class Solution
{
public:
	//删除字符串中的空格
	void DeleteBlank(char *s);
	//替换字符串中的空格为"%20"
	void ReplaceSpace(char string[],int length);
	Solution();
	~Solution();

private:

};

void Solution::DeleteBlank(char *s)
{
	char *p1 = s;
	char *p2 = s;

	while ('\0'!=*p1)
	{
		if (' '!=*p2)
		{
			*p1++ = *p2++;
		}
		else
		{
			p2++;
		}
	}
}

void Solution::ReplaceSpace(char string[], int length)
{
	int i;
	int blank_number = 0;
	int new_string_length;
	int point1,point2;
	//判断字符串是否为NULL与空串
	if (string == NULL && length <= 0)
	{
		return;
	}

	//统计字符串中的空格的个数
	for ( i = 0; string[i]!='\0'; i++)
	{
		if (string[i] == ' ')
		{
			blank_number++;
		}
	}

	new_string_length = i + 2 * blank_number;
	//判断计算所得的新串是否比分配的存储空间大
	if (new_string_length > length)
	{
		return;
	}
	
	string[new_string_length] = '\0';
	//倒着
	point1 = i - 1;
	point2 = new_string_length -1;

	while (point1>=0 && point2>point1)
	{
		if (string[point1] == ' ')
		{
			string[point2--] = '0';
			string[point2--] = '2';
			string[point2--] = '%';
		}
		else
		{
			string[point2--] = string[point1];
		}

		point1--;
	}
}

Solution::Solution()
{
}

Solution::~Solution()
{
}

int main()
{
	Solution solution;

	char *string = new char[50];
	char test[100] = "we are    happy";
	cout <<"Not Delete The Blank:"<< test << endl;
	solution.DeleteBlank(test);
	cout << "After Delete The Blank:"<< test << endl;

	//Input character
	while (gets(string))
	{
		solution.ReplaceSpace(string, 50);
		//Output the character
		puts(string);
	}
	
	system("pause");
	return 0;
}

/*
思路：
（1）如果从前往后进行遍历字符串，那么保存在字符串后面的字符肯定会被覆盖，因此考虑从后往前进行替换
（2）我们首先遍历原字符串，求出字符串中空格的个数，然后可以求出新的字符串的长度
（3）设置两个指针point1和point2分别指向原字符串和新的字符串的末尾，
（4）如果point1所指的位置不为空则将所指内容赋值给point2所指的位置
（5）如果point1所指的位置为空，则point2所指的位置开始赋值“%20”
（6）直到point1==point2的时候停止，表明字符串中的所有空格都替换完毕了。
*/