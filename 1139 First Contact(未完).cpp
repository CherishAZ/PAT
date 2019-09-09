#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int M = 10010;

vector<int> v[M];
unordered_map<int, bool> isPair;
struct node{
	int a, b;
};
int cmp(node n1, node n2){
	return n1.a != n2.a ? n1.a < n2.a : n1.b < n2.b;
}
int main()
{
	int n, m, k, t1, t2;
	string s1, s2;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> s1 >> s2;
		if(s1.length() == s2.length()){
			v[abs(stoi(s1))].push_back(abs(stoi(s2)));
			v[abs(stoi(s2))].push_back(abs(stoi(s1)));
		}
		isPair[abs(stoi(s1)) * 10000 + abs(stoi(s2))] = isPair[abs(stoi(s2)) * 10000 + abs(stoi(s1))] = true;
	}
	cin >> k;
	vector<node> ss;
	for(int l = 0; l < k; l++){
		ss.clear();
		cin >> t1 >> t2;
		t1 = abs(t1), t2 = abs(t2);
		for(int i = 0; i < v[t1].size(); i++){
			for(int j = 0; j < v[t2].size(); j++){
				if(v[t1][i] == t2 || v[t2][j] == t1) continue;
				if(isPair[v[t1][i] * 10000 + v[t2][j]]) 
				ss.push_back(node{v[t1][i], v[t2][j]});
			}
		}
		sort(ss.begin(), ss.end(), cmp);
		printf("%d\n", ss.size());
		for(auto it:ss) printf("%04d %04d\n", it.a, it.b);
	}
	return 0;
}
