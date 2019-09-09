#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int M = 500;
const int INF = 1 << 30;

int G[M][M];
int a[M], num[M];
int main()
{
	fill(G[0], G[0] + M * M, INF);
	int n, m, t1, t2;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> t1 >> t2;
		G[t1][t2] = G[t2][t1] = 1;
	}
	int k, k1;
	cin >> k;
	for(int i = 0; i < k; i++){
		int flag = 1, greater2 = 0;
		cin >> k1;
		memset(num, 0, sizeof(num));
		for(int j = 0; j < k1; j++){
			cin >> a[j];
			num[a[j]]++;
		}
		for(int j = 1; j <= n; j++){
			if(num[j] == 0 || num[j] > 2) flag = 0;
			if(num[j] == 2) greater2++;
		}
		if(greater2 != 1) flag = 0;
		if(a[0] != a[k1 - 1] || flag == 0){
			cout << "NO" << endl;
		}else{
			for(int j = 0; j < k1 - 1; j++){
				int v1 = a[j], v2 = a[j + 1];
				if(G[v1][v2] == INF){
					flag = 0;
					break;
				}
			}
			if(flag == 0) cout << "NO" << endl;
			else cout << "YES" << endl;
		}
	}
	return 0;
}
