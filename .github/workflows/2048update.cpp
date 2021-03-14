#include<bits/stdc++.h>
#include<conio.h>
#include "function 2048.h"
using namespace std;



void command(char command){
	int a[4][4] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	if(command == 'w'){
		up(a);
		checkover(a);
		addblock(a);
		disp(a);
	}else if(command == 's'){
		down(a);
		checkover(a);
		addblock(a);
		disp(a);
	}else if(command == 'a'){
		left(a);
		checkover(a);
		addblock(a);
		disp(a);
	}else if(command == 'd'){
		right(a);
		checkover(a);
		addblock(a);
		disp(a);
	}	
}

int main(){
	int a[4][4] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	char comm;
	//cout << "Do you want to play 2048???\n";
	//cout << "Press n to play!!!!!";
	cin >> comm;
	if(comm == 'n'){
		addblock(a);
		disp(a);
	}
	while(true){
	cin >> comm;
	command(comm);
	}
    return 0;
}
