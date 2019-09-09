#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXV = 520;
const int INF = 1000000000;

int vis[MAXV] = {false};
int G[MAXV][MAXV];//距离 
int d[MAXV];//最短距离 
int team[MAXV];//帮手数 
int num[MAXV] = {0}, maxN[MAXV] = {0}, n, m, c1, c2;

void dijkstra(int c){
	d[c] = 0;
	num[c] = 1;
	maxN[c] = team[c];//初始化一定要完整 
	for(int i = 0; i < n; i++){
		int u = -1, MIN = INF;
		for(int j = 0; j < n; j++){
			if(!vis[j] && d[j] < MIN){
				MIN = d[j];
				u = j;
			}
		}
		if(u == -1) return;
		vis[u] = true; // 不要忘记标记u被访问 
		for(int v = 0; v < n; v++){
			if(!vis[v] && G[u][v] != INF){
				if(d[u] + G[u][v] < d[v]){
						d[v] = d[u] + G[u][v];
						maxN[v] = maxN[u] + team[v];//更新也要完整，全面 
						num[v] = num[u];
				}else if(d[u] + G[u][v] == d[v]){
					num[v] += num[u];
					if(maxN[u] + team[v] > maxN[v]) maxN[v] = maxN[u] + team[v];
					
				}
			}
		}
	}
}
int main()
{
	int t1, t2, t3;
	fill(d, d + MAXV, INF);
	fill(G[0], G[0] + MAXV * MAXV, INF);
	cin >> n >> m >> c1 >> c2;
	for(int i = 0; i < n; i++) cin >> team[i];
	for(int i = 0; i < m; i++){
		cin >> t1 >> t2 >> t3;
		G[t1][t2] = t3;
		G[t2][t1] = t3;
	}
	dijkstra(c1);
	cout << num[c2] << " " << maxN[c2] << endl;
	return 0;
} 
