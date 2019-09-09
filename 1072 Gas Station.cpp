#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int M  =  1020;
const int INF = 1000000000;

int n, m, k, ds, G[M][M], d[M];
bool vis[M] = {false};
void dijkstra(int s){
	memset(vis, false, sizeof(vis));
	fill(d , d + M, INF);
	d[s] = 0;
	for(int i = 0; i < n + m; i++){
		int u = -1, MIN = INF;
		for(int j = 1; j <= n + m; j++){
			if(!vis[j] && d[j] < MIN){
				u = j;
				MIN = d[j];
			}
		}
		if(u == -1) return;
		vis[u] = true;
		for(int v = 1; v <= n + m; v++){
			if(!vis[v] && G[u][v] != INF && d[u] + G[u][v] < d[v]) d[v] = G[u][v] + d[u];
		}
	}
}
int getId(string s){
	int ans = 0;
	if(s[0] == 'G'){
		for(int i = 1; i < s.length(); i++){
			ans = ans * 10 + (s[i] - '0');
		}
		return ans + n;
	}
	else{
		for(int i = 0; i < s.length(); i++){
			ans = ans * 10 + (s[i] - '0');
		}
		return ans;
	}
	
}
int main()
{
	cin >> n >> m >> k >> ds;
	int u, v, w;
	string c1, c2;
	fill(G[0], G[0] + M * M, INF);
	for(int i = 0; i < k; i++){
		cin >> c1 >> c2 >> w;
		u = getId(c1);
		v = getId(c2);
		G[u][v] = G[v][u] = w;
	}
	double ansDis = -1, ansAvg = INF;
	int ansId = -1;
	for(int i = n + 1; i <= n + m; i++){
		double minDis = INF, avg = 0;
		dijkstra(i);
		for(int j = 1; j <= n; j++){
			if(d[j] > ds){
				minDis = -1;
				break;
			}
			if(d[j] < minDis) minDis = d[j];
			avg += 1.0 * d[j] / n;
		}
		if(minDis == -1) continue;
		if(minDis > ansDis){
			ansDis = minDis;
			ansAvg = avg;
			ansId = i;
		}else if(minDis == ansDis && avg < ansAvg){
			ansId = i;
			ansAvg = avg;
		}	
	}
	if(ansId == -1) cout << "No Solution" << endl;
	else{
		cout << "G" << ansId - n << endl;
		printf("%.1f %.1f\n", ansDis, ansAvg);
	}
	return 0; 
 } 
