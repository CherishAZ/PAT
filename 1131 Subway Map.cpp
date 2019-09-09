#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int M = 10100;
const int INF = 1<<30;

struct node{
	int v, dis;
};
vector<node> adj[M];
int d[M], G[M][M];
int father[M]; //确定几号线 
int n, m, input[M];
void dijkstra(int s){
	
}
int main()
{
	fill(G[0], G[0] + M * M, INF);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> m;
		memset(input, 0, sizeof(input));
		for(int j = 0; j < m; j++){
			cin >> input[j];
			//lines
		}
		node temp;
		for(int j = 0; j < m; j++){
			for(int jj = 0; jj < m; jj++){
				temp.dis = abs(jj - j);
				temp.v = input[jj];
				if(j != jj) adj[input[j]].push_back(temp);
			}
		}
	}
	int k, st, ed;
	cin >> k;
	while(k--){
		cin >> st >> ed;
		dijkstra(
	}
	return 0;
}
