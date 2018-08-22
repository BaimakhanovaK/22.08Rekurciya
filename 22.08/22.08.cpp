// 22.08.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include<ctime>
#include <algorithm>

using namespace std;

int summa = 0;
const int n=6;
const int m=7;
int arr[n][m] = { {1,0,0,0,0,1,0},
				  {0,1,1,0,0,0,0},
				  {1,0,0,1,0,0,1},
				  {0,0,0,0,1,0,0},
				  {0,1,0,0,0,0,1},
				  {0,0,0,0,0,1,0} };

bool fs[n][m] = { 0 };

void print_char(int n) {
	if (n == 0) return;
	char c;
	cin >> c;
	print_char(n-1);
	cout << c << endl; }

//void print(int n) {
//	if (n == 0) return;
//	cout << char(97 + n);
//	print(n - 1); }

void func(int x) {
	static int y=10;
	y += x;
	
	cout << y << endl;
}

void elka(int n) {

	static int k = 1;

	if (n == 0) return;

	for (int i = 1; i < n; i++)
		cout <<' ';
	for (int i = 1; i <= k; i++)
		cout <<'*';
	for (int i = 1; i < n; i++)
		cout << ' ';
	cout << endl;
	k += 2;

	elka(n - 1);
}
int fib(int n) {
	if (n == 1 || n == 0) return 1;
	else
		return fib(n - 1) + fib(n - 2);
}

int fib1(int n) {
	int f1 = 1;
	int f2=1;
	int f3;
	
	for (int i = 2; i <= n; i++)
		{
			f3 = f2;
			f2 +=f1;
			f1 = f3;
		}
	return f2;
}

void inf(int i, int j) {
	if ((j >= 0 && j < m) && (i >= 0 && i < n))
	{
		summa++;

		fs[i][j] = true;
		if (arr[i][j - 1] != 0 && fs[i][j - 1] == false) inf(i, j - 1);
		if (arr[i][j + 1] != 0 && fs[i][j + 1] == false) inf(i, j + 1);
		if (arr[i - 1][j] != 0 && fs[i - 1][j] == false) inf(i - 1, j);
		if (arr[i + 1][j] != 0 && fs[i + 1][j] == false) inf(i + 1, j);
		if (arr[i - 1][j - 1] != 0 && fs[i - 1][j - 1] == false) inf(i - 1, j - 1);
		if (arr[i - 1][j + 1] != 0 && fs[i - 1][j + 1] == false) inf(i - 1, j + 1);
		if (arr[i + 1][j - 1] != 0 && fs[i + 1][j - 1] == false) inf(i + 1, j - 1);
		if (arr[i + 1][j + 1] != 0 && fs[i + 1][j + 1] == false) inf(i + 1, j + 1);

		cout << i << " " << j << endl;
	}
}







int main()
{
	
	inf(1, 2);
	cout << summa;

	

	system("pause");
    return 0;
}

