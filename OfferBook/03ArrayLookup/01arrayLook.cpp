#include<iostream>
#include<string>
using namespace std;

bool search(int *matrix, int rows, int columns, int key)
{
	bool isFound = false;
	if (matrix!=NULL && rows>0 && columns>0)
	{
		int row = 0;
		int column = columns - 1;
		while (row<rows && column>=0)
		{
			if (matrix[row*columns + column]==key)
			{
				isFound = true;
				break;
			}
			else if (matrix[row*columns + column] > key)
			{
				column--;
			}
			else
			{
				row++;
			}
		}
	}
	return isFound;
}

int main()
{
	int key;
	//int a[4][4] = { 1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15 };
	const int rows = 4;
	const int columns = 4;
	int b[rows][columns] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	cout << "输入要查找的值" << endl;
	cin >> key;
	cout << search(b[0],rows,columns,key) << endl;
	system("pause");
}