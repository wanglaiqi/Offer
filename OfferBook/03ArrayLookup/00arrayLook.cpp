#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

/*
����һ����������Ķ�ά���飬����Ҫ���ҵ�Ԫ��
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
	cout << "�������ά���������������" << endl;
	while ((scanf("%d%d", &m, &n)) != EOF)
	{
		int key;
		cout << "������Ҫ���ҵ�����" << endl;
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