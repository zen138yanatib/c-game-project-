// ZKTP2048.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include <bits/stdc++.h>
#include <fstream>
#include <cstdlib>

#include <exception>
#include <string>

#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

#include "function2048.h"

using namespace std;
using namespace cgicc;

const char* sarray = "A1X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0";
int score;

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

void writeScore(string name, int score) {

	ofstream myfile;

	time_t rawtime;
	struct tm* timeinfo;
	char buffer[80];
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, 80, "%F-%X", timeinfo);

	myfile.open("c:\\xampp\\cgi-bin\\player.txt", fstream::in | fstream::out | fstream::app);
	myfile << "name:" << name << " score:" << score << " time:" << buffer << endl;
	myfile.close();

	return;
}

int main() {

	//cout << "\n\n\n\n\t\t\t2048 GAME\n\n\n\t\tPress any key to continue";
	//_getch();
	//system("cls");
	Cgicc cgi;

	cout << HTTPHTMLHeader() << HTMLDoctype(HTMLDoctype::eStrict) << endl;
	cout << html().set("lang", "en").set("dir", "ltr") << endl;

	// Set up the page's header and title.
	cout << head() << endl;
	cout << title() << "2048" << title() << endl;

	cout << "<head>" << endl;
	cout << "    <title>ZKTP</title>" << endl;
	cout << "<link rel=\"stylesheet\" href=\"/style.css\">" << endl;
	cout << "</head>" << endl;
	cout << "<body>" << endl;
	cout << "    <nav> " << endl;
	cout << "        <div class=\"container\">" << endl;
	cout << "            <div class=\"nav - con\">" << endl;
	cout << "                <div class=\"logo\">" << endl;
	cout << "                    <h1>ZKTP</h1>" << endl;
	cout << "                    <h1 class=\"color2048\">2048</h1>" << endl;
	cout << "                </div>" << endl;
	cout << "                <ul class=\"menu\">" << endl;
	cout << "                    <li><a href=\"table.exe\">Score</a></li>" << endl;
	cout << "                    <li><a href=\"ZKTP2048.exe\">Reset</a></li>" << endl;
	cout << "                </ul>" << endl;
	cout << "            </div>" << endl;
	cout << "        </div>" << endl;
	cout << "    </nav>" << endl;
	cout << "" << endl;
	cout << "    <header>" << endl;
	cout << "        <section>" << endl;
	cout << "            <h1>Project</h1>" << endl;
	cout << "            <p> </p>" << endl;
	cout << "" << endl;
	cout << "        </section>" << endl;
	cout << "<form action = \"ZKTP2048.exe\" method = \"get\">" << endl;
	cout << "        <div class=\"user\">" << endl;
	cout << "            <h3>User Name</h3>" << endl;
	cout << "            <input name = \"name\" type=\"text\">" << endl;
	cout << "            <input name = \"namtbtn\" type=\"submit\" class=\"btn-1\">" << endl;
	cout << "        </div>" << endl;
	cout << "</form>";
	cout << "    </header>" << endl;
	cout << "    <main>" << endl;
	cout << "        <h1>GAME</h1>" << endl;
	cout << "      <div class=\"container\">" << endl;
	cout << "        <section class=\"p\">" << endl;
	cout << "            <div class=\"game-board\">" << endl;
	
	int i1, i2, i3, i4, i, j;
	int a[4][4] = { 0 }, tmp[4][4] = { 0 };
	int arrow;
	string name = "zen";
	if (cgi.getElements().size() > 0) {

		const_form_iterator iter;
		for (iter = cgi.getElements().begin(); iter != cgi.getElements().end(); ++iter) {

			string formName = iter->getName();
			//cout << "form name=" << formName << "<br>" << endl;
			if (formName.compare("arrow")==0) {
				string str = iter->getValue();
				sarray = str.c_str();
				sscanf_s(sarray, "A%dX%dX%dX%dX%dX%dX%dX%dX%dX%dX%dX%dX%dX%dX%dX%dX%d",
					&arrow,
					&a[0][0], &a[0][1], &a[0][2], &a[0][3],
					&a[1][0], &a[1][1], &a[1][2], &a[1][3],
					&a[2][0], &a[2][1], &a[2][2], &a[2][3],
					&a[3][0], &a[3][1], &a[3][2], &a[3][3]);

				//cout << "<h1>pass1</h1> arrow=" << arrow << endl;

				command(a, arrow);
			}else if (formName.compare("name") == 0) {
				name = iter->getValue();
				srand(time(0));
				i1 = rand() % 4;
				i2 = rand() % 4;
				while (1) {
					i3 = rand() % 4;
					i4 = rand() % 4;
					if (i3 != i1 && i4 != i2) break;
				}
				a[i1][i2] = 2;
				a[i3][i4] = 4;
				//cout << "form value=" << name << "<br>" << endl;
			}
		}

	} else {

		//cout << "<h1>pass2</h1>" << endl;

		srand(time(0));
		i1 = rand() % 4;
		i2 = rand() % 4;
		while (1){
			i3 = rand() % 4;
			i4 = rand() % 4;
			if (i3 != i1 && i4 != i2) break;
		}
		a[i1][i2] = 2;
		a[i3][i4] = 4;
	}

	disp(a);

	cout << "            </div>" << endl;
	cout << "        </section>" << endl;
	cout << "      </div>" << endl;
	cout << "<form action = \"ZKTP2048.exe\" method = \"get\">" << endl;
	cout << "<input name = \"name\" type=\"hidden\" value=\"" << name << "\" >" << endl;
	cout << "Choose :" << endl;
	cout << "<button name = \"arrow\" type = \"submit\" value = \"A75" << varArray << "\" class=\"btn-1\">LEFT</button>" << endl;
	cout << "<button name = \"arrow\" type = \"submit\" value = \"A72" << varArray << "\" class=\"btn-1\">UP</button>" << endl;
	cout << "<button name = \"arrow\" type = \"submit\" value = \"A80" << varArray << "\" class=\"btn-1\">DOWN</button>" << endl;
	cout << "<button name = \"arrow\" type = \"submit\" value = \"A77" << varArray << "\" class=\"btn-1\">RIGHT</button>" << endl;
	cout << "</form>";
	cout << "    </main>" << endl;
	cout << "<h2>Name : " << name << "</h2>" << endl;
	cout << "<h2>Score : " << lastscore << "</h2>" << endl;

	if (!checkover(a)) {
		cout << "<h1>Game Over</h1>" << endl;
		writeScore(name,lastscore);
	}

	cout << "" << endl;
	cout << "    <footer>" << endl;
	cout << "        <p>project by Zensoodlor soodtae Khaotom Phurin</p>" << endl;
	cout << "    </footer>" << endl;
	cout << "</body>" << endl;
	cout << "</html>" << endl;

}
