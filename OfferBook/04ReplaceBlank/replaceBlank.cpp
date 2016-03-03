#include<iostream>
#include<string>
using namespace std;

/*
*使用字符串替换空格
*we are happy
*we%20are%20happy
*/

void RepalceBlank(char str[], int length)
{
	if (str==NULL || length<=0 )
	{
		return;
	}

	int originLength = 0;
	int numberOfBlank = 0;
	int i = 0;
	int newLength = 0;
	//获得原始字符串的长度和空格的个数
	while (str[i] != '\0')
	{
		originLength++;
		if (str[i]==' ')
		{
			numberOfBlank++;
		}
		i++;
	}
	//新字符串的长度
	newLength = originLength + numberOfBlank * 2;

	if (newLength > length)
	{
		return;
	}

	int indexOfOrigin = originLength;
	int indexOfNew = newLength;

	//替换空格的操作
	while (indexOfOrigin>=0 && indexOfNew>indexOfOrigin)
	{
		if (str[indexOfOrigin] == ' ')
		{
			str[indexOfNew--] = '0';
			str[indexOfNew--] = '2';
			str[indexOfNew--] = '%';
		}
		else
		{
			str[indexOfNew --] = str[indexOfOrigin];
		}
		indexOfOrigin--;
	}
}

int main()
{
	int j = 0;
	const int space = 100;
	char str[space] = " we are happy ";
	RepalceBlank(str,space);
	while (str[j]!='\0')
	{
		cout << str[j];
		j++;
	}
	cout << endl;
	system("pause");
	//return 0;
}