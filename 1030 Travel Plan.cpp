#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int M = 520;
const int INF = 1000000000;
int n, m, s, ed;
int d[M], G[M][M], cost[M][M], c[M], pre[M];
bool vis[M] = {false};
//vector<int> pre[M];
void dijkstra(int v){
	d[v] = 0;
	c[v] = 0;
	for(int i = 0; i < n; i++) pre[i] = i;
	for(int i = 0; i < n; i++){
		int u = -1, MIN = INF;
		for(int j = 0; j < n; j++){
			if(!vis[j] && d[j] < MIN){
				MIN = d[j];
				u = j;
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int v = 0; v < n; v++){
			if(!vis[v] && G[u][v] != INF){
				if(d[v] > d[u] + G[u][v]){
					d[v] = d[u] + G[u][v];
					c[v] = c[u] + cost[u][v];
					pre[v] = u;
				}else if(d[v] == d[u] + G[u][v]){
					if(c[u] + cost[u][v] < c[v]){
						c[v] = c[u] + cost[u][v];
						pre[v] = u;
					}
				}
			}
		}
	}
}
void DFS(int v){
	if(v == s){
		cout << v << " ";
		return;
	}
	DFS(pre[v]);
	cout << v << " ";
}
int main()
{
	int t1, t2;
	fill(c, c + M, INF);
	fill(d, d + M, INF);
	fill(G[0], G[0] + M * M, INF);
	cin >> n >> m >> s >> ed;
	for(int i = 0; i < m; i++){
		cin >> t1 >> t2;
		cin >> G[t1][t2] >> cost[t1][t2];
		G[t2][t1] = G[t1][t2];
		cost[t2][t1] = cost[t1][t2];
	}
	dijkstra(s);
	DFS(ed);
	cout << d[ed] << " " << c[ed];
	return 0;
}
