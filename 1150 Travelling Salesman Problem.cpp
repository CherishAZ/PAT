#include <iostream>
#include <cstring>
#include <set>
#include <vector>
using namespace std;
const int M = 210;
const int INF = 1<<30;

int G[M][M], minDis = INF, pos = -1;
set<int> st;
vector<int> ss;
int main()
{
	int n, m, t1, t2, dis1, t, k1, k;
	cin >> n >> m;
	fill(G[0], G[0] + M * M, INF);
	for(int i = 0; i < m; i++){
		cin >> t1 >> t2 >> dis1;
		G[t1][t2] = G[t2][t1] = dis1;
	}
	cin >> k;
	for(int i = 1; i <= k; i++){
		cin >> k1;
		st.clear();
		ss.clear();
		int flag = 1, dis = 0;
		for(int j = 0; j < k1; j++){
			cin >> t;
			st.insert(t);
			ss.push_back(t);
		}
		for(int j = 0; j < ss.size() - 1; j++){
			if(G[ss[j]][ss[j + 1]] != INF){
				dis += G[ss[j]][ss[j + 1]];
			}else{
				flag = 0;//NA
				break;
			}
		}
		if(flag != 0){
			if(st.size() < n || ss[0] != *ss.rbegin()) flag = 3;//NOT A TS CYCLE
			else if(ss.size() > n + 1 && st.size() == n) flag = 2;//NOT SIMPLE
		}
		if(flag == 0) cout << "Path " << i << ": NA (Not a TS cycle)" << endl;
		else if(flag == 1) cout << "Path " << i << ": " << dis << " (TS simple cycle)" << endl;
		else if(flag == 2) cout << "Path " << i << ": " << dis << " (TS cycle)" << endl;
		else if(flag == 3) cout << "Path " << i << ": " << dis << " (Not a TS cycle)" << endl;
		if(dis < minDis && (flag == 1 || flag == 2)){
			minDis = dis;
			pos = i;
		}
	}
	cout << "Shortest Dist(" << pos << ") = " << minDis << endl;
	return 0;
} 
