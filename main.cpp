#include <iostream>
#include "matrix.h"
#include <stdlib.h>
using namespace std;

int main()
{
	float arr[][2] = { {1,2},{3,4},{5,6} };
	float arr1[][2] = { {1,2},{3,4},{5,6} };
	float arr2[][2] = { {1,2},{3,4},{5,6} };
	int rows = sizeof(arr) / sizeof(arr[0]);
	int cols = sizeof(arr[0]) / sizeof(arr[0][0]);
	float p[100];


	avgRows((float*)arr, rows, cols, p);
	cout << "ÿ�о�ֵΪ��" << endl;
	print(p, rows);
	cout << endl;


	avgCols((float*)arr, rows, cols, p);
	cout << "ÿ�о�ֵΪ��" << endl;
	print(p, cols);
	cout << endl;


	int x;
	cout << "��������ɾȥ������" << endl;
	cin >> x;

	removeRows((float*)arr1, rows, cols, x);
	cout << "ɾȥ��" << x << "�к�����飺" << endl;
	for (int i = 0; i < rows - 1; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr1[i][j] << " " ;
		}
		cout << endl;
	}
	
	int y;
	cout << "��������ɾȥ������" << endl;
	cin >> y;

	removeCols((float*)arr2, rows, cols, y);
	cout << "ɾȥ��" << y << "�к�����飺" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols-1; j++)
		{
			cout << arr2[i][j] << " ";
		}
		cout << endl;
	}

	
	float p1[100];
	cout << "������һ��" << cols << "ά������" << endl;
	for (int i = 0; i < cols; i++) {
		cin >> p1[i];
	}
	multiply((float*)arr, p1, rows, cols, p);
	cout << "��˽���ǣ�" << endl;
	print(p,cols);

	getchar();
	getchar();

	return 0;
}