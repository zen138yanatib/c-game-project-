#include<bits/stdc++.h>

using namespace std;

//*func up

void up(int a[N][N]){
	int i,j,x,y;
	for(j=0;j<N;j++){
		x=0,y=j;
		for(i=1;i<N;i++){
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

void down(int a[N][N]){
	int i,j,x,y;
	for(j=0;j<N;j++){
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

void left(int a[N][N]){
	int i,j,x,y;
	for(i=0;i<N;i++){
		x=i,y=0;
		for(j=1;j<N;j++){
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

void right(int a[N][N]){
	int i,j,x,y;
	for(i=0;i<N;i++){
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


