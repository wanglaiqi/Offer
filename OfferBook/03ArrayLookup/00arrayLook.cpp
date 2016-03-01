#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

/*
输入一个行列有序的二维数组，输入要查找的元素
*/

string search(int b[][100],int rows,int columns,int key)
{
	int row = 0;
	int col = columns - 1;
	while (row<rows && col>=0)
	{
		if (b[row][col]==key)
		{
			return "YES";
		}
		else if (b[row][col]>key)
		{
			col--;
		}
		else
		{
			row++;
		}
	}
	return "NO";
}

int main()
{
	int m, n;
	int a[100][100];
	cout << "请输入二维数组的行数和列数" << endl;
	while ((scanf("%d%d", &m, &n)) != EOF)
	{
		int key;
		cout << "请输入要查找的数字" << endl;
		cin >> key;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> a[i][j];
			}
		}
		cout << search(a,m,n,key) <<endl;
	}
	system("pause");
}