#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int MAXV = 520;
const int INF = 1000000000;

struct node{
	int v, dis;
}nn;
vector<node> adj[MAXV];
int vis[MAXV] = {false};
int d[MAXV];//最短距离 
int team[MAXV];
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
		for(int v1 = 0; v1 < adj[u].size(); v1++){
			node k = adj[u][v1];
			if(vis[k.v] == false){
				if(d[u] + k.dis < d[k.v]){
					d[k.v] = d[u] + k.dis;
					num[k.v] = num[u];
					maxN[k.v] = maxN[u] + team[k.v];
				}else if(d[u] + k.dis == d[k.v]){
					num[k.v] += num[u];
					if(maxN[u] + team[k.v] > maxN[k.v]) maxN[k.v] = maxN[u] + team[k.v];
				}
			
			}
		}
	}
}
int main()
{
	int t1, t2, t3;
	fill(d, d + MAXV, INF);
	cin >> n >> m >> c1 >> c2;
	for(int i = 0; i < n; i++) cin >> team[i];
	for(int i = 0; i < m; i++){
		cin >> t1 >> t2 >> t3;
		nn.v = t2;
		nn.dis = t3;
		adj[t1].push_back(nn);
		nn.v = t1;
		adj[t2].push_back(nn);//双向赋值 
	}
	dijkstra(c1);
	cout << num[c2] << " " << maxN[c2] << endl;
	return 0;
} 
