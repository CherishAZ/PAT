#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
const int M = 210;
const int INF = 1000000000;

int n, k, G[M][M], d[M], happiness[M] = {0}, num[M], max_happiness = 0;
double ave_happiness  = 0.0;
string st, ed = "ROM";
bool vis[M] = {false};
vector<int> pre[M];
vector<int> tempPath, path;
map<string, int> nameToid;
map<int, string> idToname;
void dijkstra(){
	num[0] = 1;
	d[0] = 0;
	for(int i = 0; i < n; i++){
		int u = -1, MIN = INF;
		for(int j = 0; j < n; j++){
			if(!vis[j] && MIN > d[j]){
				MIN = d[j];
				u = j;
			}	
		}
		if( u == -1) return;
		vis[u] = true;
		for(int v = 0; v < n; v++){
			if(!vis[v] && G[u][v] != INF){
				if(d[u] + G[u][v] < d[v]){
					d[v] = d[u] + G[u][v];
					pre[v].clear();
					pre[v].push_back(u);//p的前驱是u 
					num[v] = num[u];
				}else if(d[u] + G[u][v] == d[v]){
					num[v] += num[u];
					pre[v].push_back(u);//p的前驱是u 
				}
			}
		} 
	}
}

void dfs(int v){
	if(v == 0){
		tempPath.push_back(v);
		int temp_happiness = 0;
		for(int i = tempPath.size() - 1; i >= 0; i--){
			int id = tempPath[i];
			cout << "id: " << id << endl;
			temp_happiness += happiness[id];
		}
		double ave_temp_happiness = 1.0 * temp_happiness / (tempPath.size() - 1);
		if(temp_happiness > max_happiness){
			max_happiness = temp_happiness;
			ave_happiness = ave_temp_happiness;
			path = tempPath;
		}else if(temp_happiness == max_happiness && ave_temp_happiness > ave_happiness){
			path = tempPath;
			ave_happiness = ave_temp_happiness;
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for(int i = 0; i < pre[v].size(); i++) dfs(pre[v][i]);
	tempPath.pop_back();
}
int main()
{
	int tt;
	string s1, s2;
	fill(d, d + M, INF);
	fill(G[0], G[0] + M * M, INF);
	cin >> n >> k >> st;
	nameToid[st] = 0;
	idToname[0] = st;
	for(int i = 1; i < n; i++){
		cin >> s1 >> happiness[i];
		nameToid[s1] = i;
		idToname[i] = s1;
	}
	for(int i = 0; i < k; i++){
		cin >> s1 >> s2 >> tt;
		int u = nameToid[s1];
		int v = nameToid[s2];
		G[v][u] = G[u][v] = tt;
	}
	dijkstra();
	dfs(nameToid[ed]);
	cout << num[nameToid[ed]] << " " << d[nameToid[ed]] << " " << max_happiness << " " << (int)ave_happiness << endl;
	for(int i = path.size() - 1; i >= 0; i--){
		cout << idToname[path[i]];
		if(i != 0) cout << "->";
	}
	return 0;
}

