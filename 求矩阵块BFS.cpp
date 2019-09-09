#include <iostream>
#include <queue>
using namespace std;

struct node{
	int x, y;
}nn;
int m, n;
int matrix[100][100];
bool inq[100][100] = {false};
int X[4] = {1, -1, 0, 0}, Y[4] = {0, 0, 1, -1};
bool judge(int x, int y){
	if( x >= m || x < 0 || y >= n || y < 0) return false;
	if(matrix[x][y] == 0 || inq[x][y] == true) return false;
	return true;
}
int bfs(int x, int y){
	int nx, ny;
	queue<node> q;
	nn.x = x, nn.y = y;
	q.push(nn);
	inq[x][y] = true;
	while(!q.empty()){
		node t = q.front();
		q.pop();
		for(int i = 0; i < 4; i++){
			nx = t.x + X[i];
			ny = t.y + Y[i];
			if(judge(nx, ny)){
				nn.x = nx, nn.y = ny;
				q.push(nn);
				inq[nx][ny] = true;
			}
		}
	}
}
int main()
{ 
	int ans = 0;
	scanf("%d%d", &m, &n);
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &matrix[i][j]);
		
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(matrix[i][j] == 1 && !inq[i][j]){
				ans++;
				bfs(i, j);	
			}
		
		}
	} 
	printf("%d\n", ans);
}

/*
6 7
1 1 1 1 0 0 1
0 0 1 0 0 0 0
0 0 0 0 1 0 0
0 0 0 1 1 1 0
1 1 1 0 1 0 0
1 1 1 1 0 0 0
*/
