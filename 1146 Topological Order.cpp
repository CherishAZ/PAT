#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int M = 10010;

vector<int> adj[1010];
int inDegree[M] = {0}, inD[M];
int main()
{
	int n, m, t1, t2, k, t;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> t1 >> t2;
		adj[t1].emplace_back(t2);
		inDegree[t2]++;
	}
	vector<int> ss;
	cin >> k;
	for(int i = 0; i < k; i++){
		int flag = 1;
		memcpy(inD, inDegree, sizeof(inDegree));//Ã¿´ÎÅÐ¶Ï¸³ÖµinD 
		for(int j = 0; j < n; j++){
			cin >> t;
			if(inD[t] != 0){
				flag = 0;
			}else{
				for(int v = 0; v < adj[t].size(); v++){
					inD[adj[t][v]]--;
				}
			}
		}
		if(flag == 0) ss.emplace_back(i);
	}
	for(int i = 0; i < ss.size(); i++){
		cout << ss[i];
		if(i != ss.size() - 1) cout << " ";
	}
	return 0;
}
