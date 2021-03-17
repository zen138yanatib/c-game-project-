#include <exception>
#include <iostream>
#include <conio.h>
#include <bits/stdc++.h>
#include<string>

#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

using namespace std;
using namespace cgicc;


//*func up

void up(int a[4][4]) {
	int i, j, x, y;
	for (j = 0; j < 4; j++) {
		x = 0, y = j;
		for (i = 1; i < 4; i++) {
			if (a[i][j] != 0) {
				if (a[i - 1][j] == 0 || a[i - 1][j] == a[i][j]) {
					if (a[x][y] == a[i][j]) {
						a[x][y] *= 2;
						a[i][j] = 0;
					}
					else {
						if (a[x][y] == 0) {
							a[x][y] = a[i][j];
							a[i][j] = 0;
						}
						else {
							a[++x][y] = a[i][j];
							a[i][j] = 0;
						}
					}
				}
				else x++;
			}
		}
	}
}

//*func down

void down(int a[4][4]) {
	int i, j, x, y;
	for (j = 0; j < 4; j++) {
		x = 3, y = j;
		for (i = 2; i >= 0; i--) {
			if (a[i][j] != 0) {
				if (a[i + 1][j] == 0 || a[i + 1][j] == a[i][j]) {
					if (a[x][y] == a[i][j]) {
						a[x][y] *= 2;
						a[i][j] = 0;
					}
					else {
						if (a[x][y] == 0) {
							a[x][y] = a[i][j];
							a[i][j] = 0;
						}
						else {
							a[--x][y] = a[i][j];
							a[i][j] = 0;
						}
					}
				}
				else x--;
			}
		}
	}
}

//*func left

void left(int a[4][4]) {
	int i, j, x, y;
	for (i = 0; i < 4; i++) {
		x = i, y = 0;
		for (j = 1; j < 4; j++) {
			if (a[i][j] != 0) {
				if (a[i][j - 1] == 0 || a[i][j - 1] == a[i][j]) {
					if (a[x][y] == a[i][j]) {
						a[x][y] *= 2;
						a[i][j] = 0;
					}
					else {
						if (a[x][y] == 0) {
							a[x][y] = a[i][j];
							a[i][j] = 0;
						}
						else {
							a[x][++y] = a[i][j];
							a[i][j] = 0;
						}
					}
				}
				else y++;
			}
		}
	}
}

//*func right

void right(int a[4][4]) {
	int i, j, x, y;
	for (i = 0; i < 4; i++) {
		x = i, y = 3;
		for (j = 2; j >= 0; j--) {
			if (a[i][j] != 0) {
				if (a[i][j + 1] == 0 || a[i][j + 1] == a[i][j]) {
					if (a[x][y] == a[i][j]) {
						a[x][y] *= 2;
						a[i][j] = 0;
					}
					else {
						if (a[x][y] == 0) {
							a[x][y] = a[i][j];
							a[i][j] = 0;
						}
						else {
							a[x][--y] = a[i][j];
							a[i][j] = 0;
						}
					}
				}
				else y--;
			}
		}
	}
}

void addblock(int a[4][4])
{
	int x, y;
	srand(time(0));
	while (1)
	{
		x = rand() % 4;
		y = rand() % 4;
		if (a[x][y] == 0)
		{
			a[x][y] = pow(2, x % 2 + 1);
			break;
		}
	}

}

void disp(int a[4][4])
{
	string varArray = "";
	int i, j;
	std::cout << "<table>" << endl;
	for (i = 0; i < 4; i++)
	{
		std::cout << "<tr>" << endl;
		for (j = 0; j < 4; j++)
		{
			std::cout << "<td><h4>" << a[i][j] << "</h4></td>" << endl;
			varArray = varArray + "X" + to_string(a[i][j]);
		}
		std::cout << "</tr>" << endl;
	}
	std::cout << "</table>" << endl;
	std::cout << "<form action = \"ZKTP2048.exe\" method = \"get\">" << endl;
	std::cout << "Choose :" << endl;
	std::cout << "<button name = \"arrow\" type = \"submit\" value = \"A75" << varArray << "\">LEFT</button>" << endl;
	std::cout << "<button name = \"arrow\" type = \"submit\" value = \"A72" << varArray << "\">UP</button>" << endl;
	std::cout << "<button name = \"arrow\" type = \"submit\" value = \"A80" << varArray << "\">DOWN</button>" << endl;
	std::cout << "<button name = \"arrow\" type = \"submit\" value = \"A77" << varArray << "\">RIGHT</button>" << endl;
	std::cout << "</form>";
}

int check(int tmp[4][4], int a[4][4])
{
	int x = 1, i, j;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			if (tmp[i][j] != a[i][j])
			{
				x = 0;
				break;
			}
	return x;
}

int checkover(int a[4][4])
{
	int x = 0, y = 0, i, j;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			if (a[i][j] == 0)
			{
				x = 1;
				break;
			}

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (a[i + 1][j] == a[i][j] || a[i][j + 1] == a[i][j])
			{
				y = 1;
				break;
			}

	if (x || y) return 1;
	else return 0;
}
