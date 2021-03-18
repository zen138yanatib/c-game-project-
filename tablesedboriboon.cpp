#include <iostream>
#include <fstream>
#include <ctime>
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

using namespace std;
using namespace cgicc;

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

struct Score {
	char name[128];
	int score;
	char dateTime[128];
};

int compareByScore(const void* score1, const void* score2) {
	return ((Score*)score1)->score < ((Score*)score2)->score ? 1 : -1;
}

Score scores[10240];
int readScore() {

	ifstream myReadFile("c:\\xampp\\cgi-bin\\player.txt");

	char line[1024];
	int index = 0;
	srand(time(NULL));
	for (index = 0; index < 10240 && myReadFile.getline(line, 1024); index++) {
		//cout << line << endl;
		scores[index] = Score();
		sscanf(line, "name:%s score:%d time:%s", scores[index].name, &(scores[index].score), scores[index].dateTime);
		//scores[index].score = rand() % 1024;
		//cout << " ==> index=" << index << " name:" << scores[index].name << " score:" << scores[index].score << " dateTime:" << scores[index].dateTime << endl;
	}

	qsort(scores, index, sizeof(Score), compareByScore);
	//cout << " ==> index=" << index << " name:" << scores[index].name << " score:" << scores[index].score << " dateTime:" << scores[index].dateTime << endl;

	//for (int i = 0; i < index; i++) {
	//	cout << scores[i].score << endl;
	//}

	myReadFile.close();

	return index;
}

int main()
{
	int maxLen = readScore();

	cout << HTTPHTMLHeader() << HTMLDoctype(HTMLDoctype::eStrict) << endl;
	cout << "<html lang=\"en\">" << endl;
	cout << "    <head>" << endl;
	cout << "        <title>ZKTP</title>" << endl;
	cout << "    <link rel=\"stylesheet\" href=\"/style.css\">" << endl;
	cout << "    </head>" << endl;
	cout << "    <body>" << endl;
	cout << "        <nav> " << endl;
	cout << "            <div class=\"container\">" << endl;
	cout << "                <div class=\"nav-con\">" << endl;
	cout << "                    <div class=\"logo\">" << endl;
	cout << "                        <h1>ZKTP</h1>" << endl;
	cout << "                        <h1 class=\"color2048\">2048</h1>" << endl;
	cout << "                    </div>" << endl;
	cout << "                <ul class=\"menu\">" << endl;
	cout << "                    <li><a href=\"ZKTP2048.exe\">Back</a></li>" << endl;
	cout << "                </ul>" << endl;
	cout << "                </div>" << endl;
	cout << "            </div>" << endl;
	cout << "        </nav>" << endl;
	cout << "        <h1 class=\"score\">Score</h1>" << endl;
	cout << "        <table class=\"tables\"> " << endl;
	cout << "            <thead>" << endl;
	cout << "                <tr>" << endl;
	cout << "                    <th>Rank</th>" << endl;
	cout << "                    <th>Name</th>" << endl;
	cout << "                    <th>Points</th>" << endl;
	cout << "                </tr>" << endl;
	cout << "            </thead>" << endl;
	cout << "            <tbody>" << endl;
	for(int i = 0; i < maxLen; i++) {
		cout << "                <tr>" << endl;
		cout << "                    <td>" << i+1 << "</td>" << endl;
		cout << "                    <td>" << scores[i].name << "</td>" << endl;
		cout << "                    <td>" << scores[i].score << "</td>" << endl;
		cout << "                </tr>" << endl;	
	}
	cout << "            </tbody>" << endl;
	cout << "        </table>" << endl;
	cout << "    </body>" << endl;
	cout << "</html>" << endl;
}
