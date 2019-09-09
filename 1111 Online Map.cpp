#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int M = 1000;
const int INF = 1 << 30;

int n, m, st, ed, minD = INF, minT1 = INF, minT = INF;
int G[M][M], T[M][M], d[M], t[M];
bool vis[M] = {false};
vector<int> pre[M], pret[M];
void dijkstra(int s){
	fill(d, d + M, INF);
	d[s] = 0;
	for(int i = 0; i < n; i++){
		int u = -1, MIN = INF;
		for(int j = 0; j < n ; j++){
			if(!vis[j] && d[j] < MIN){
				MIN = d[j];
				u = j;
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int v = 0; v < n; v++){
			if(!vis[v] && G[u][v] != INF){
				if(d[u] + G[u][v] < d[v]){
					d[v] = d[u] + G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}else if(d[v] == d[u] + G[u][v]){
					pre[v].push_back(u);
				}
			}
		}
	}
}
vector<int> tempPath, path;
void dfs(int v){
	if(v == st){
		tempPath.push_back(v);
		int dis = 0, ttime = 0;
		for(int i = tempPath.size() - 1; i > 0; i--){
			int v1 = tempPath[i], v2 = tempPath[i - 1];
			dis += G[v1][v2];
			ttime += T[v1][v2];
		}
		if(dis < minD){
			minD = dis;
			minT1 = ttime;
			path = tempPath;
		}else if(dis == minD){
			if(ttime < minT1){
				minT1 = ttime;
				path = tempPath;
			}
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for(int i = 0; i < pre[v].size(); i++) dfs(pre[v][i]);
	tempPath.pop_back();
}
vector<int> tempPath1, path1;
void dijkstra_t(int s){
	memset(vis, false, sizeof(vis));
	fill(t, t + M, INF);
	t[s] = 0;
	for(int i = 0; i < n; i++){
		int u = -1, MIN = INF;
		for(int j = 0; j < n ; j++){
			if(!vis[j] && t[j] < MIN){
				MIN = t[j];
				u = j;
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int v = 0; v < n; v++){
			if(!vis[v] && T[u][v] != INF){
				if(t[u] + T[u][v] < t[v]){
					t[v] = t[u] + T[u][v];
					pret[v].clear();
					pret[v].push_back(u);
				}else if(t[v] == t[u] + T[u][v]){
					pret[v].push_back(u);
				}
			}
		}
	}
}
void dfs_t(int v){
	if(v == st){
		int tempminT = 0;
		tempPath1.push_back(v);
		for(int i = tempPath1.size() - 1; i > 0; i--){
			int v1 = tempPath1[i], v2 = tempPath1[i - 1];
			tempminT += T[v1][v2];
		}
		if(tempminT < minT){
			minT = tempminT;
			path1 = tempPath1;
		}else if(tempminT == minT){
			if(tempPath1.size() < path1.size()){
				path1 = tempPath1;
			}
		}
		tempPath1.pop_back();
		return;
	}
	tempPath1.push_back(v);
	for(int i = 0; i < pret[v].size(); i++) dfs_t(pret[v][i]);
	tempPath1.pop_back();
}


int main()
{
	fill(G[0], G[0] + M * M, INF);
	fill(T[0], T[0] + M * M, INF);
	int t1, t2, one, len, time;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> t1 >> t2 >> one >> len >> time;
		if(one){
			G[t1][t2] = len;
			T[t1][t2] = time;
		}else{
			G[t1][t2] = G[t2][t1] = len;
			T[t1][t2] = T[t2][t1] = time;
		}
	}
	cin >> st >> ed;
	dijkstra(st);
	dfs(ed);
	dijkstra_t(st);
	dfs_t(ed);
	if(path == path1){
		cout << "Distance = " << minD <<"; Time = " << minT << ":";
		for(int i = path.size() - 1; i > 0; i--){
			cout << " " << path[i] << " ->"; 
		}
		cout << " " << path[0] << endl;
	}else{
		cout << "Distance = " << minD <<":";
		for(int i = path.size() - 1; i > 0; i--){
			cout << " " << path[i] << " ->"; 
		}
		cout << " " << path[0] << endl;
		cout << "Time = " << minT <<":";
		for(int i = path1.size() - 1; i > 0; i--){
			cout << " " << path1[i] << " ->"; 
		}
		cout << " " << path1[0];
	}
	return 0;
}
