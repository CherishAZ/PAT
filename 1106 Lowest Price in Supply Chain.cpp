#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int n, minlayer = -1, sum = 0, flag = 1, level[100010] = {0};
double p, r,  rate;
vector<int> nn[100010];
void bfs(int root){
	queue<int> q;
	q.push(root);
	level[root] = 0;
	while(!q.empty()){
		int top = q.front();
		q.pop();
		if(nn[top].size() == 0 && flag){
			minlayer = level[top];
			flag = 0;
		}
		if(level[top] == minlayer) sum++;
		if(level[top] > minlayer && !flag) return;
		for(int i = 0; i < nn[top].size(); i++){
			q.push(nn[top][i]);
			level[nn[top][i]] = level[top] + 1;
		}
	}
}
int main()
{
	int t1, t2;
	scanf("%d%lf%lf", &n, &p, &r);
	rate = 1.0 + r/100;
	for(int i = 0; i < n; i++){
		scanf("%d", &t1);
		if(t1 != 0){
			for(int j = 0; j < t1; j++){
				scanf("%d", &t2);
				nn[i].push_back(t2);
			}
		}
	}
	bfs(0);
	printf("%.4lf %d", pow(rate, minlayer) * p, minlayer);
	return 0;
}
