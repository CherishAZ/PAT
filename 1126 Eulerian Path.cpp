#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[520];
int num[520], sum = 0;
bool vis[520] = {false};
void dfs(int v){
	sum++;
	vis[v] = true;
	for(int i = 0; i < adj[v].size(); i++){
		if(!vis[adj[v][i]]) dfs(adj[v][i]);
	}
}
int main()
{
	int n, m, t1, t2, even = 0, odd = 0;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> t1 >> t2;
		adj[t1].emplace_back(t2);
		adj[t2].emplace_back(t1);
		num[t1]++;
		num[t2]++;
	}
	for(int i = 1; i <= n; i++){
		cout << num[i];
		if(i != n) cout << " ";
		if(num[i] % 2) odd++;
		else even++;
	}
	cout << endl;
	dfs(1);
	if(sum == n && odd == 0) cout << "Eulerian";
	else if(sum == n && odd == 2) cout << "Semi-Eulerian";
	else cout << "Non-Eulerian";
	return 0;
}
