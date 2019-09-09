#include <iostream>
#include <vector>
using namespace std;

int n, m;
int num[100] = {0}, l = 0;//leave, l²ãÊı 
struct node{
	vector<int> child;
}nn[110];
void dfs(int index, int layer){
	if(index > n) return;
	if(nn[index].child.size() == 0){
		num[layer]++;
		l = max(l, layer);
		return;
	}
	
	for(int i = 0; i < nn[index].child.size(); i++){
		int temp = nn[index].child[i];
		dfs(temp, layer + 1);
	}
}
int main()
{
	int t1, t2, t3;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d%d", &t1, &t2);
		for(int j = 0; j < t2; j++){
			scanf("%d", &t3);
			nn[t1].child.push_back(t3);
		} 
	}
	dfs(1, 1);
	cout << l << endl;
	for(int i = 1; i <= l; i++){
		if(i != 1 ) printf(" ");
		printf("%d", num[i]);
	}
	return 0;
 } 
