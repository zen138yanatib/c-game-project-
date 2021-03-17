// ZKTP2048.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include <bits/stdc++.h>

#include <exception>
#include<string>

#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

#include "function2048.h"

using namespace std;
using namespace cgicc;

const char* sarray = "A1X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0";

void command(int command[4][4], int ch) {
	int tmp[4][4] = { 0 };
	{
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				tmp[i][j] = command[i][j];
		//ch = _getch();
		//system("cls");
		if (ch == 72) up(command);
		if (ch == 80) down(command);
		if (ch == 75) left(command);
		if (ch == 77) right(command);

		if (!check(tmp, command))
			addblock(command);
		//disp(command);

		if (!checkover(command))
		{
			//cout << "\n\n\t\t\tGAME OVER!!\n\n\n";
			//_getch();
		}
	}

}

int main() {
	//cout << "\n\n\n\n\t\t\t2048 GAME\n\n\n\t\tPress any key to continue";
	//_getch();
	//system("cls");
	Cgicc cgi;
	int i1, i2, i3, i4, i, j;
	int a[4][4] = { 0 }, tmp[4][4] = { 0 };
	int arrow;
	if (cgi.getElements().size() > 0) {
		const_form_iterator iter;
		for (iter = cgi.getElements().begin(); iter != cgi.getElements().end(); ++iter) {
			//iter->getName();
			string str = iter->getValue();
			sarray = str.c_str();
		}
		sscanf_s(sarray, "A%dX%dX%dX%dX%dX%dX%dX%dX%dX%dX%dX%dX%dX%dX%dX%dX%d",
			&arrow,
			&a[0][0], &a[0][1], &a[0][2], &a[0][3],
			&a[1][0], &a[1][1], &a[1][2], &a[1][3],
			&a[2][0], &a[2][1], &a[2][2], &a[2][3],
			&a[3][0], &a[3][1], &a[3][2], &a[3][3]);
		command(a,arrow);
	} else {
		srand(time(0));
		i1 = rand() % 4;
		i2 = rand() % 4;
		while (1)
		{
			i3 = rand() % 4;
			i4 = rand() % 4;
			if (i3 != i1 && i4 != i2) break;
		}
		a[i1][i2] = 2;
		a[i3][i4] = 4;
	}

	cout << HTTPHTMLHeader() << HTMLDoctype(HTMLDoctype::eStrict) << endl;
	cout << html().set("lang", "en").set("dir", "ltr") << endl;

	// Set up the page's header and title.
	cout << head() << endl;
	cout << title() << "2048" << title() << endl;

	cout << "<style>" << endl;
	cout << "table, td, th{" << endl;
	cout << "  border: 1px solid black;" << endl;
	cout << "}" << endl;
	cout << "table{" << endl;
	cout << "  width: 100 %;" << endl;
	cout << "  border - collapse: collapse;" << endl;
	cout << "}" << endl;
	cout << "</style>" << endl;

	disp(a);

	cout << body() << html();
	//command(a)
}

