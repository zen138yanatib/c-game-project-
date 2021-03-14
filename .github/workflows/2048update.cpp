#include<bits/stdc++.h>
#include<conio.h>
#include "function 2048.h"
using namespace std;



void command(int command[4][4]){
	int ch,tmp[4][4]={0};
	while (1)
    {
    	for(int i=0;i<4;i++)
    		for(int j=0;j<4;j++)
    			tmp[i][j]=command[i][j];
    	ch=getch();
    	system("cls");
    	if(ch==72) up(command);
    	if(ch==80) down(command);
    	if(ch==75) left(command);
    	if(ch==77) right(command);
		if(ch==27) break;
		
		if(!check(tmp,command))
			addblock(command);
		disp(command);
			
		if(!checkover(command))
		{
			cout<<"\n\n\t\t\tGAME OVER!!\n\n\n";
			getch();
			break;
		}	
	}

}

int main(){
		cout<<"\n\n\n\n\t\t\t2048 GAME\n\n\n\t\tPress any key to continue";
	getch();
	system("cls");
	int i1,i2,i3,i4,i,j;
	int a[4][4]={0},tmp[4][4]={0};
	srand(time(0));
	i1=rand()%4;
	i2=rand()%4;
	while(1)
	{
		i3=rand()%4;
		i4=rand()%4;
		if(i3!=i1 && i4!=i2) break;
	}
	a[i1][i2]=2;
	a[i3][i4]=4;
	disp(a);
	
	command(a);
	
}
