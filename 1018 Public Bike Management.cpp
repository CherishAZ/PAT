#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int M = 510;
const int INF = 1000000000;

int c, n, sp, m, minRemain = INF, minNeed = INF;
int num[M], G[M][M], d[M];
bool vis[M] = {false};
vector<int> pre[M];
void dijkstra(int s){
	fill(d, d + M, INF);
	d[s] = 0;
	for(int i = 0; i < n; i++){
		int u = -1, MIN = INF;
		for(int j = 0; j <= n; j++){
			if(!vis[j] && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int v = 0; v <= n; v++){
			if(!vis[v] && G[u][v] != INF){
				if(d[u] + G[u][v] < d[v]){
					d[v] = d[u] + G[u][v];
					pre[v].clear();
					pre[v].emplace_back(u);
				}else if(d[v] == d[u] + G[u][v]){
					pre[v].emplace_back(u);
				}
			}
		}
	}
}
vector<int> tempPath, path;
void dfs(int s){
	if(s == 0){
		int need = 0, remain = 0;
		tempPath.emplace_back(0);
		for(int i = tempPath.size() - 1; i >= 0; i--){
			int id = tempPath[i];
			if(num[id] > 0) remain += num[id];
			else{
				if(remain > abs(num[id])) remain -= abs(num[id]);
				else{
					need += abs(num[id]) - remain;
					remain = 0;
				}
			}
		}
		if(need < minNeed){
			minNeed = need;
			minRemain = remain;
			path = tempPath;
		}else if(need == minNeed && remain < minRemain){
			minRemain = remain;
			path = tempPath;
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(s);
	for(int i = 0; i < pre[s].size(); i++) dfs(pre[s][i]);
	tempPath.pop_back();
}
int main()
{
	int u, v, w;
	fill(G[0], G[0] + M * M, INF);
	cin >> c >> n >> sp >> m;
	for(int i = 1; i <= n; i++){
		cin >> num[i];
		num[i] -= c / 2;
	}
	for(int i = 0; i < m; i++){
		cin >> u >> v >> w;
		G[u][v] = G[v][u] = w;
	}
	dijkstra(0);
	dfs(sp);
	cout << minNeed << " ";
	for(int i = path.size() - 1; i >= 0; i--){
		cout << path[i];
		if(i != 0) cout << "->";
	}
	cout << " " << minRemain;
	return 0;
}
