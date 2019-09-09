#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int M = 110;
const int INF = 1<<30;

int G[M][M], num[M];
vector<int> ss, adj[M];
int main(){
	fill(G[0], G[0] + M * M, INF);
	int n, m, t, t1, t2, k, k1;
	cin >> n >> m;
	for(int i = 0; i <= n; i++) G[i][i] = 1;
	for(int i = 0; i < m; i++){
		cin >> t1 >> t2;
		G[t1][t2] = G[t2][t1] = 1;
		adj[t1].emplace_back(t2);
		adj[t2].emplace_back(t1);
	}
	cin >> k;
	while(k--){
		ss.clear();
		memset(num, 0, sizeof(num));
		cin >> k1;
		int flag = 1, sum = 0;
		for(int i = 0; i < k1; i++){
			cin >> t;
			ss.emplace_back(t);
		}
		for(int i = 0; i < ss.size() - 1; i++){
			for(int j = i; j < ss.size(); j++){
				if(G[ss[i]][ss[j]] == INF){
					flag = 0;
					break;
				}
			}
		}
		if(flag != 0){
			for(int i = 0; i < ss.size(); i++){
				for(int j = 0; j < adj[ss[i]].size(); j++){
					num[adj[ss[i]][j]]++;//给出的点涉及的边的另一个点+1 
				}
			}
			for(int i = 1; i <= n; i++){
				if(num[i] == k1) sum++;//共同且未列入的点，num是等于k1 
			}
			if(sum != 0) flag = 2;
		}
		if(flag == 0){
			cout << "Not a Clique" << endl;
		}else if(flag == 2){
			cout << "Not Maximal" << endl;
		}else if(flag == 1) cout << "Yes" << endl;
	}
	return 0;
}
