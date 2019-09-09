#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, ll = 0, num = 0;//ll为最大层数, num应从0开始(例如一个结点时会执行一次num++)
double p, r;
vector<int> nn[100010];
void dfs(int index, int layer){
	if(nn[index].size() == 0){
		if(layer > ll){
			ll = layer;
			num = 1;
		}
		else if(ll == layer) num++;
		return;
	}
	for(int i = 0; i < nn[index].size(); i++) dfs(nn[index][i], layer + 1);
}
int main()
{
	int t, first;
	scanf("%d%lf%lf", &n, &p, &r);
	for(int i = 0; i < n; i++){
		scanf("%d",&t);
		if(t != -1) nn[t].push_back(i);
		else  first = i;
	}
	dfs(first, 0);
	printf("%.2lf %d\n",pow(1.0 + r/100, ll) * p, num);
	return 0; 
}
