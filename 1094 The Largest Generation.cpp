//层次遍历树 
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;//结点以及非叶子结点数 
int layer1 = 1, num[100] = {0};//层以及数目 
int maxlayer = 1, maxnum = 0;
bool flag[110] = {false};//确定root 
struct node{
	int layer;
	vector<int> child;
}nn[110];
void LayerOrder(int t){
	queue<int> q;
	q.push(t);
	nn[t].layer = 1;
	while(!q.empty()){
		int top = q.front();
		num[nn[top].layer]++;
		q.pop();
		for(int i = 0; i < nn[top].child.size(); i++){
			int temp = nn[top].child[i];
			q.push(temp);
			nn[temp].layer = nn[top].layer + 1;
			if(nn[temp].layer > layer1) layer1 = nn[temp].layer;
		}
	}
}
//void dfs(int index, int level){
//	num[level]++;
//	for(int j = 0; j < nn[index].child.size(); j++) dfs(nn[index].child[j], level + 1);
//}
int main()
{
	int t1, t2, t3, first = 1;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d%d", &t1, &t2);
		for(int j = 0; j < t2; j++){
			scanf("%d", &t3);
			nn[t1].child.push_back(t3);
			flag[t3] = true;
		}
	}
	for(; first < n; first++)
	if(!flag[first]) break;
	LayerOrder(first);
	cout << layer1 << endl;
	for(int i = 1; i <= layer1; i++){
		if(num[i] > maxnum){
			maxlayer = i;
			maxnum = num[i];
		}
	}
	printf("%d %d\n", maxnum, maxlayer);
	return 0;
	
//	dfs(1, 1);
//	for(int i = 1; i < 101; i++){
//		if(num[i] > maxnum){
//			maxlayer = i;
//			maxnum = num[i];
//		}
//	}
//	printf("%d %d\n", maxnum, maxlayer);
//	return 0;
}
