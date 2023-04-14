#include <iostream>
#include<string.h>
using namespace std;
#define MAX 8
int board[MAX][MAX] = {0};

void print(int m)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1) {
				cout << "Q ";
			}
			else cout << ". ";
		}
		cout << endl;
	}
}

bool check( int row, int col, int m)
{
	int i, j;
	for (i = 0; i < col; i++)
	{
		if (board[row][i]) {
			return false;
		}
	}
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
		if (board[i][j]) {
			return false;
		}
	}
	for (i = row, j = col; j >= 0 && i < m; i++, j--) {
		if (board[i][j]) {
			return false;
		}
	}
	return true;
}

bool findQueen(int col, int m)
{
	if (col >= m) {
		return true;
	}
	for (int i = 0; i < m; i++) {
		if (check( i, col, m)) {
			board[i][col] = 1;
			if (findQueen( col + 1,m))
				return true;
			board[i][col] = 0;
		}
	}
	return false;
}

bool solveNQ(int m)
{
	
	if (findQueen( 0, m) == true) {
		cout << "\nCach bo tri quan hau la: \n";
		print(m);
		return true;
	}
}

int main()
{
	int m;
	cout << "Nhap so quan hau va kich thuoc ban co: ";
	cin >> m;
	solveNQ(m);
	system("pause");
	return 0;
}