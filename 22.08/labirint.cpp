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
				  {1,1,1,0,0,0,0},
				  {1,0,1,1,0,0,1},
				  {0,0,0,1,1,0,0},
				  {0,1,0,0,1,1,1},
				  {0,0,0,0,0,0,1} };

bool fs[n][m] = { 0 };



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

	
		if (i == 5 && j == 6)
			cout << "vixod iz labirinta"<<endl;
	}
}

int main()
{
	inf(0,0);

	system("pause");
    return 0;
}

