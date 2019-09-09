#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
double p, r, sum = 0.0, rate;
struct node{
	int num;
	vector<int> child;
}nn[100010];
void dfs(int index, int layer){
	if(nn[index].child.size() == 0){
		sum += nn[index].num * pow(rate, layer - 1);
		return ;
	}
	for(int i = 0; i < nn[index].child.size(); i++){
		int temp = nn[index].child[i];
		dfs(temp, layer + 1);
	} 
}
int main()
{
	int t1, t2;
	scanf("%d%lf%lf", &n, &p, &r);
	rate = 1.0 + r/100;
	for(int i = 0; i < n; i++){
		scanf("%d", &t1);
		if(t1 == 0){
			scanf("%d", &t2);
			nn[i].num = t2;
		}
		else{
			for(int j = 0; j < t1; j++){
				scanf("%d", &t2);
				nn[i].child.push_back(t2);
			}
		}
	}
	dfs(0, 1);
	printf("%.1lf", p * sum);
	return 0;
} 
 
