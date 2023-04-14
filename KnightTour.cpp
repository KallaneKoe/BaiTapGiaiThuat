#include<iostream>
#include<stdio.h>
#define MAX 8
using namespace std;
 
int BOARD[MAX][MAX] = { 0 };
int MoveX[8] = { -2,-2,-1,-1, 1, 1, 2, 2};
int MoveY[8] = { -1, 1,-2, 2,-2, 2,-1, 1};
int dem = 0;

 
void xuat(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%2d ", BOARD[i][j]);
		cout << endl;
	}
	cout << endl;
}
 
void diChuyen(int x, int y, int n) {
	++dem;
	BOARD[x][y] = dem;
	for (int i = 0; i < 8; i++)	{
		if (dem == n * n) {
			cout << "Cac buoc di la: \n";
			xuat(n);
			system("pause");
			exit(0);
		}

		int u = x + MoveX[i];
		int v = y + MoveY[i];

		if (u >= 0 && u < n&&v >= 0 && v < n&& BOARD[u][v] == 0)
			diChuyen(u, v,n);
	}

	--dem;
	BOARD[x][y] = 0;
}
int main() {
	int a, b, n;
	cout << "Nhap n: ";
	cin >> n;
	cout << "Nhap vi tri ban dau.\nx: ";
	cin>>a;
	cout << "y: ";
	cin >> b;
	diChuyen(a, b,n);
	cout << "Khong tim thay duong di";
	system("pause");

}