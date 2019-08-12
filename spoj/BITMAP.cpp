#include<cstdio>
#include<iostream>
#include<string>
#include<cstdlib>
#include<queue>
#include<stack>
#include<utility>
#include<string>
#include<cstring>
#include<set>
#include<vector>
#include<fstream>
#include<map>
#include<list>
#include<algorithm>
#define MAX 10000000
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)

using namespace std;

queue<int> myq;

void bfs(char mat[182][182], int dis[182][182], int x, int y, int r, int c){
	
	int i, j, a, b;
	
	dis[x][y] = 0;
	myq.push(x);
	myq.push(y);
	
	while(!myq.empty()){
		
		i = myq.front();
		myq.pop();
		j = myq.front();
		myq.pop();
		
		a = i-1;
		b = j;
		
		if(in_range(a, b, r, c) && dis[a][b] > dis[i][j] + 1 && mat[a][b] == '0'){
			myq.push(a);
			myq.push(b);
			dis[a][b] = dis[i][j] + 1;
		}
		
		a = i+1;
		b = j;
		
		if(in_range(a, b, r, c) && dis[a][b] > dis[i][j] + 1 && mat[a][b] == '0'){
			myq.push(a);
			myq.push(b);
			dis[a][b] = dis[i][j] + 1;
		}
		
		a = i;
		b = j-1;
		
		if(in_range(a, b, r, c) && dis[a][b] > dis[i][j] + 1 && mat[a][b] == '0'){
			myq.push(a);
			myq.push(b);
			dis[a][b] = dis[i][j] + 1;
		}
		
		a = i;
		b = j+1;
		
		if(in_range(a, b, r, c) && dis[a][b] > dis[i][j] + 1 && mat[a][b] == '0'){
			myq.push(a);
			myq.push(b);
			dis[a][b] = dis[i][j] + 1;
		}
		
	}
}

int main(){
	
	char mat[182][182], ch;
	int t, r, c, dis[182][182];
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%c", &r, &c, &ch);
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				scanf("%c", &mat[i][j]);
				dis[i][j] = MAX;
			}
			scanf("%c", &ch);
		}
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++){
				if(mat[i][j] == '1')
					bfs(mat, dis, i, j, r, c);
			}
			
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++)
				printf("%d ", dis[i][j]);
			printf("\n");
		}
	}
	
    return 0;
}