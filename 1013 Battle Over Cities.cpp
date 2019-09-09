#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> G[1010], cc;
bool vis[1010]; 
int t3;
void dfs(int v){
	if(v == t3) return;
	vis[v] = true;
	for(int i = 0; i < G[v].size(); i++){
		if(vis[G[v][i]] == false) dfs(G[v][i]);
	}
}
int main()
{
	int n, m, k;
	int t1, t2;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < m; i++){
		cin >> t1 >> t2;
		G[t1].emplace_back(t2);
		G[t2].emplace_back(t1);
	}
	for(int i = 0; i < k; i++){
		scanf("%d", &t3);
		memset(vis, false, sizeof(vis));//每次先初始化 
		int block = 0;
		for(int i = 1; i <= n; i++){
			if( i != t3 && vis[i] == false){
				dfs(i);
				block++;
			}
		}
		printf("%d\n", block - 1);
	}
}
