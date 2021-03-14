#include<bits/stdc++.h>
#include<conio.h>

using namespace std;

//*func up

void up(int a[4][4]){
	int i,j,x,y;
	for(j=0;j<4;j++){
		x=0,y=j;
		for(i=1;i<4;i++){
			if(a[i][j]!=0){
				if(a[i-1][j]==0 || a[i-1][j]==a[i][j]){
					if(a[x][y]==a[i][j]){
						a[x][y]*=2;
						a[i][j]=0;
					}else{
						if(a[x][y]==0){
							a[x][y]=a[i][j];
							a[i][j]=0;
						}else{
							a[++x][y]=a[i][j];
							a[i][j]=0;
						}
					}
				}else x++;
			}
		}
	}
}

//*func down

void down(int a[4][4]){
	int i,j,x,y;
	for(j=0;j<4;j++){
		x=3,y=j;
		for(i=2;i>=0;i--){
			if(a[i][j]!=0){
				if(a[i+1][j]==0 || a[i+1][j]==a[i][j]){
					if(a[x][y]==a[i][j]){
						a[x][y]*=2;
						a[i][j]=0;
					}else{
						if(a[x][y]==0){
							a[x][y]=a[i][j];
							a[i][j]=0;
						}else{
							a[--x][y]=a[i][j];
							a[i][j]=0;
						}
					}
				}else x--;
			}
		}
	}
}

//*func left

void left(int a[4][4]){
	int i,j,x,y;
	for(i=0;i<4;i++){
		x=i,y=0;
		for(j=1;j<4;j++){
			if(a[i][j]!=0){
				if(a[i][j-1]==0 || a[i][j-1]==a[i][j]){
					if(a[x][y]==a[i][j]){
						a[x][y]*=2;
						a[i][j]=0;
					}else{
						if(a[x][y]==0){
							a[x][y]=a[i][j];
							a[i][j]=0;
						}else{
							a[x][++y]=a[i][j];
							a[i][j]=0;
						}
					}
				}else y++;
			}
		}
	}
}

//*func right

void right(int a[4][4]){
	int i,j,x,y;
	for(i=0;i<4;i++){
		x=i,y=3;
		for(j=2;j>=0;j--){
			if(a[i][j]!=0){
				if(a[i][j+1]==0 || a[i][j+1]==a[i][j]){
					if(a[x][y]==a[i][j]){
						a[x][y]*=2;
						a[i][j]=0;
					}else{
						if(a[x][y]==0){
							a[x][y]=a[i][j];
							a[i][j]=0;
						}else{
							a[x][--y]=a[i][j];
							a[i][j]=0;
						}
					}
				}else y--;
			}
		}
	}
}

void addblock(int a[4][4])
{
	int x,y;
	srand(time(0));
	while(true)
	{
		x=rand()%4;
		y=rand()%4;
		if(a[x][y]==0)
		{
			a[x][y]=2;
			break;
		}
	}

}

// int checkscore(){
// 	int score;
// 	for(int i=0; i<16; i++){
// 		for(int j=0; j<16; j++){
// 			score += a[i][j];
// 		}
// 	}
// 	return score;
// }

void disp(int a[4][4])
{
	cout<<"\n\t\tPress Esc anytime to quit the game";
	cout<<"\n\n\n\n";
	int i,j;
	for(i=0;i<4;i++)
	{
		cout<<"\t\t\t\t-----------------\n\t\t\t\t";
		for(j=0;j<4;j++)
		{
			if(a[i][j]==0) cout<<"|   ";
			else
				cout<<"| "<<a[i][j]<<" ";
		}
		cout<<"|"<<endl;
	}
	cout<<"\t\t\t\t-----------------\n";
}

int check(int tmp[4][4],int a[4][4])
{
	int x=1,i,j;
	for(i=0;i<4;i++)
    	for(j=0;j<4;j++)
    		if(tmp[i][j]!=a[i][j])
    		{
    			x=0;
    			break;
			}
	return x;
}

int checkover(int a[4][4])
{
	int x=0,y=0,i,j;
	for(i=0;i<4;i++)
    	for(j=0;j<4;j++)
    		if(a[i][j]==0)
    		{
    			x=1;
				break;	
			}
			
	for(i=0;i<3;i++)
    	for(j=0;j<3;j++)
    		if(a[i+1][j]==a[i][j] || a[i][j+1]==a[i][j])
    		{
    			y = 1;
    			break;
			}
			
	if(x || y) return 1;
	else return 0;
}

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
	cin >> comm;
	command(comm);
	cin >> comm;
	command(comm);
	cin >> comm;
	command(comm);
	cin >> comm;
	command(comm);
    return 0;
}
