#include <iostream>
using namespace std;
int main() {
	cout << "���е�Ϊ�ڶ�������" << endl;
	int m, n, c;
	cin >> m;
	cin >> n;

	char array1[100][100];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
		{
			cin >> array1[i][j];
		}
	}
	// ��������������г�ʼ��

	cin >> c;

	// �����滻
	int array2[2][100];
	int a = 0, b = 0,k = 1;
	while (k <= c)
	{
		for (int i = 0; i < n; i++) {
			for ( int j = 0; j < m; j++) {
				if (array1[i][j] == 'X')
				{
					array2[b][a] = i;
					array2[b + 1][a] = j;
					a++;
				}
			}
		}
		for ( i = 0; i < a; i++) {
			if (array2[b][i] == 0) {

				if (array2[b + 1][i] == 0)
				{
					if (array1[array2[b][i] + 1][array2[b + 1][i]] != 'P')
					{
						array1[array2[b][i] + 1][array2[b + 1][i]] = 'X';
					}
					if (array1[array2[b][i]][array2[b + 1][i] + 1] != 'P')
					{
						array1[array2[b][i]][array2[b + 1][i] + 1] = 'X';
					}
				}

				else if (array2[b + 1][i] == m - 1) {
					if (array1[array2[b][i] + 1][array2[b + 1][i]] != 'P')
					{
						array1[array2[b][i] + 1][array2[b + 1][i]] = 'X';
					}
					if (array1[array2[b][i]][array2[b + 1][i] - 1] != 'P')
					{
						array1[array2[b][i]][array2[b + 1][i] - 1] = 'X';
					}
				}

				else
				{
					if (array1[array2[b][i] + 1][array2[b + 1][i]] != 'P')
					{
						array1[array2[b][i] + 1][array2[b + 1][i]] = 'X';
					}
					if (array1[array2[b][i]][array2[b + 1][i] - 1] != 'P')
					{
						array1[array2[b][i]][array2[b + 1][i] - 1] = 'X';
					}
					if (array1[array2[b][i]][array2[b + 1][i] + 1] != 'P')
					{
						array1[array2[b][i]][array2[b + 1][i] + 1] = 'X';
					}
				}
			}
			else if (array2[b][i] == n - 1)
			{
				if (array2[b + 1][i] == 0) {
					if (array1[array2[b][i] - 1][array2[b + 1][i]] != 'P')
					{
						array1[array2[b][i] - 1][array2[b + 1][i]] = 'X';
					}
					if (array1[array2[b][i]][array2[b + 1][i] + 1] != 'P')
					{
						array1[array2[b][i]][array2[b + 1][i] + 1] = 'X';
					}
				}

				else if (array2[b + 1][i] == m - 1) {
					if (array1[array2[b][i] - 1][array2[b + 1][i]] != 'P')
					{
						array1[array2[b][i] - 1][array2[b + 1][i]] = 'X';
					}
					if (array1[array2[b][i]][array2[b + 1][i] - 1] != 'P')
					{
						array1[array2[b][i]][array2[b + 1][i] - 1] = 'X';
					}
				}

				else
				{
					if (array1[array2[b][i] - 1][array2[b + 1][i]] != 'P')
					{
						array1[array2[b][i] - 1][array2[b + 1][i]] = 'X';
					}
					if (array1[array2[b][i]][array2[b + 1][i] - 1] != 'P')
					{
						array1[array2[b][i]][array2[b + 1][i] - 1] = 'X';
					}
					if (array1[array2[b][i]][array2[b + 1][i] + 1] != 'P')
					{
						array1[array2[b][i]][array2[b + 1][i] + 1] = 'X';
					}
				}
			}
			else if (array2[b + 1][i] == 0) {
			if (array1[array2[b][i] - 1][array2[b + 1][i]] != 'P')
			{
				array1[array2[b][i] - 1][array2[b + 1][i]] = 'X';
			}
			if (array1[array2[b][i] + 1][array2[b + 1][i]] != 'P')
			{
				array1[array2[b][i] + 1][array2[b + 1][i]] = 'X';
			}
			if (array1[array2[b][i]][array2[b + 1][i] + 1] != 'P')
			{
				array1[array2[b][i]][array2[b + 1][i] + 1] = 'X';
			}
				}
			else if (array2[b + 1][i] == m - 1) {
			if (array1[array2[b][i] - 1][array2[b + 1][i]] != 'P')
			{
				array1[array2[b][i] - 1][array2[b + 1][i]] = 'X';
			}
			if (array1[array2[b][i] + 1][array2[b + 1][i]] != 'P')
			{
				array1[array2[b][i] + 1][array2[b + 1][i]] = 'X';
			}
			if (array1[array2[b][i]][array2[b + 1][i] - 1] != 'P')
			{
				array1[array2[b][i]][array2[b + 1][i] - 1] = 'X';
			}
				}
			else {
			if (array1[array2[b][i] - 1][array2[b + 1][i]] != 'P')
			{
				array1[array2[b][i] - 1][array2[b + 1][i]] = 'X';
			}
			if (array1[array2[b][i] + 1][array2[b + 1][i]] != 'P')
			{
				array1[array2[b][i] + 1][array2[b + 1][i]] = 'X';
			}
			if (array1[array2[b][i]][array2[b + 1][i] - 1] != 'P')
			{
				array1[array2[b][i]][array2[b + 1][i] - 1] = 'X';
			}
			if (array1[array2[b][i]][array2[b + 1][i] + 1] != 'P')
			{
				array1[array2[b][i]][array2[b + 1][i] + 1] = 'X';
			}
				}
		}
		k++;
		a = 0;
	}

	// ������
	for ( i = 0; i < n; i++)
	{
		for ( int j = 0; j < m; j++)
		{
			cout << array1[i][j];
		}
		cout << endl;
	}

	// ������һ��c++�Ļ���ģ������
	system("pause");
	return 0;
}