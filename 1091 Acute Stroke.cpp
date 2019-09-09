#include <iostream>
#include <queue>
using namespace std;

struct node{
	int x, y, z;
}nn;
int m, n, l, t;
int pixel[1290][130][61];
bool inq[1290][130][61] = {false};
int X[6] = {0, 0, 0, 0 , 1, -1};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {1, -1, 0, 0, 0, 0};

bool judge(int x,int y, int z){
	if( x>= m || x < 0 || y >= n || y < 0 || z >= l || z < 0) return false;
	if(pixel[x][y][z] == 0 || inq[x][y][z] == true) return false;
	return true;
}
int BFS(int x, int y, int z){
	int tot = 0; //计数当前块中1的个数 
	queue<node> q;
	nn.x = x, nn.y = y, nn.z = z;
	q.push(nn);
	inq[x][y][z] = true;
	while(!q.empty()){
		node top = q.front();
		q.pop();
		tot++;
		for(int i = 0; i < 6; i++){
			int newX = top.x + X[i];
			int newY = top.y + Y[i];
			int newZ = top.z + Z[i];
			if(judge(newX, newY, newZ)){
				nn.x = newX, nn.y = newY, nn.z = newZ;
				q.push(nn);
				inq[newX][newY][newZ] = true;
			}
		}
	}
	if(tot >= t) return tot;
	else return 0; 
}

int main()
{
	int temp;
	scanf("%d%d%d%d", &m, &n, &l, &t);
	for(int k = 0; k < l; k++){
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				scanf("%d", &pixel[i][j][k]);
			}
		}
	}
	int ans = 0;
	for(int k = 0; k < l; k++){
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				if(pixel[i][j][k] == 1 && inq[i][j][k] == false)
				ans += BFS(i, j , k);
			}
		}
	}
	printf("%d", ans);
	return 0;
 } 
