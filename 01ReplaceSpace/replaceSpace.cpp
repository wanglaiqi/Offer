#include<stdio.h>
#include<iostream>

using namespace std;
/*
��ʵ��һ�����������ַ����е�ÿ���ո��滻�ɡ�%20����
�������롰We are happy.�����������We%20are%20happy.
*/
class Solution
{
public:
	//ɾ���ַ����еĿո�
	void DeleteBlank(char *s);
	//�滻�ַ����еĿո�Ϊ"%20"
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
	//�ж��ַ����Ƿ�ΪNULL��մ�
	if (string == NULL && length <= 0)
	{
		return;
	}

	//ͳ���ַ����еĿո�ĸ���
	for ( i = 0; string[i]!='\0'; i++)
	{
		if (string[i] == ' ')
		{
			blank_number++;
		}
	}

	new_string_length = i + 2 * blank_number;
	//�жϼ������õ��´��Ƿ�ȷ���Ĵ洢�ռ��
	if (new_string_length > length)
	{
		return;
	}
	
	string[new_string_length] = '\0';
	//����
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
˼·��
��1�������ǰ������б����ַ�������ô�������ַ���������ַ��϶��ᱻ���ǣ���˿��ǴӺ���ǰ�����滻
��2���������ȱ���ԭ�ַ���������ַ����пո�ĸ�����Ȼ���������µ��ַ����ĳ���
��3����������ָ��point1��point2�ֱ�ָ��ԭ�ַ������µ��ַ�����ĩβ��
��4�����point1��ָ��λ�ò�Ϊ������ָ���ݸ�ֵ��point2��ָ��λ��
��5�����point1��ָ��λ��Ϊ�գ���point2��ָ��λ�ÿ�ʼ��ֵ��%20��
��6��ֱ��point1==point2��ʱ��ֹͣ�������ַ����е����пո��滻����ˡ�
*/