#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n, father[10010], maxH = 0;
bool isRoot[10010] = {false};
vector<int> G[10010];
void init(){
	for(int i = 1; i <= n; i++)
	father[i] = i;
}
int findFather(int x){
	int a = x;
	while( x != father[x] ) x = father[x];
	//路径压缩
	while(a != father[a]){
		int z = a;
		a = father[a];
		father[z] = x;
	} 
	return x;
}
void Union(int a, int b){
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB) father[faA] = faB;
	
}
//dfs depth
set<int> temp, sum;
void dfs(int u, int height, int pre){
	if(height > maxH){
		temp.clear();
		temp.insert(u);
		maxH = height;
	}else if(height == maxH) temp.insert(u);
	for(int i = 0; i < G[u].size(); i++){
		if( G[u][i] == pre) continue;
		dfs(G[u][i], height + 1, u);
	}
}

int main()
{	
	int t1, t2, ans = 0;
	scanf("%d", &n);
	init();
	for(int i = 0; i < n - 1; i++){
		scanf("%d%d", &t1, &t2);
		G[t1].emplace_back(t2);
		G[t2].emplace_back(t1);
		Union(t1, t2);
	}
	for(int i = 1; i <= n; i++) isRoot[findFather(i)] = true;//根绝点为true；
	for(int i = 1; i <= n; i++) if(isRoot[i]) ans++;
	if(ans != 1) printf("Error: %d components\n", ans);
	else{
		dfs(1, 1, -1);
		sum = temp;
		dfs(*sum.begin(), 1, -1);
		//for(set<int>::iterator it = temp.begin(); it != temp.end(); it++) sum.insert(*it);
		for(auto it : temp) sum.insert(it); 
		for(auto it : sum) printf("%d\n", it);
	}
	return 0;
}
