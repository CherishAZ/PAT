#include <iostream>
#include <vector>
using namespace std;

int m, n;
struct node{
	int x, y;
}nn;
int matrix[100][100];
bool inq[100][100] = {false};
int X[4] = {1, -1, 0, 0}, Y[4] = {0, 0, 1, -1};
bool judge(int x,int y){
	if( x >= m || x < 0 || y >= n || y < 0) return false;
	if(matrix[x][y] == 0 || inq[x][y] == true) return false;
	return true;
}
void dfs(int x, int y){
	inq[x][y] = true;
	for(int i = 0; i < 4; i++){
		if(judge(x + X[i], y + Y[i]))
			dfs( x + X[i], y + Y[i] );
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
				dfs(i, j);	
			}
		}
	} 
	printf("%d\n", ans);
}
