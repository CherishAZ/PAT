#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int M = 520;
const int INF = 1000000000;

int n, m, st, ed, G[M][M], cost[M][M];
int d[M], minCost = INF;
bool vis[M] = {false};
vector<int> pre[M];
vector<int> tempPath, path;
void Dijkstra(int s){
	d[s] = 0;
	for(int i = 0; i < n; i++){
		int u = -1, MIN = INF;
		for(int j = 0; j < n; j++){
			if(!vis[j] && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int v = 0; v < n; v++){
			if(!vis[v] && G[u][v] != INF){
				if(G[u][v] + d[u] < d[v]){
					d[v] = G[u][v] + d[u];
					pre[v].clear();
					pre[v].push_back(u);
				}else if(G[u][v] + d[u] == d[v]){
					pre[v].push_back(u);//uÎªvµÄÇ°Çý 
				}
			}
		}
	}
}

void Dfs(int v){
	if(v == st){
		tempPath.push_back(v);
		int tempCost = 0;
		for(int i = tempPath.size() - 1; i > 0; i--){
			int id = tempPath[i], idNext = tempPath[i - 1];
			tempCost += cost[id][idNext];
		}
		if(tempCost < minCost){
			minCost = tempCost;
			path = tempPath;
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for(int i = 0; i < pre[v].size(); i++) Dfs(pre[v][i]);
	tempPath.pop_back();
}
int main()
{
	cin >> n >> m >> st >> ed;
	int t1, t2;
	fill(d, d + M, INF);
	fill(cost[0], cost[0] + M * M, INF);
	fill(G[0], G[0] + M * M, INF);
	for(int i = 0; i < m; i++){
		cin >> t1 >> t2;
		cin >> G[t1][t2] >> cost[t1][t2];
		G[t2][t1] = G[t1][t2];
		cost[t2][t1] = cost[t1][t2];
	}
	Dijkstra(st);
	Dfs(ed);
	for(int i = path.size() - 1; i >= 0 ; i--) cout << path[i] << " ";
	cout << d[ed] << " " << minCost << endl;
	return 0;
}
