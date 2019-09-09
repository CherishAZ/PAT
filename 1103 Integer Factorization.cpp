#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> temp, ss;
int n, p, k, rear = -1, n1, m;//n1为x的最大值, m为确定n1范围的时间优化 
void dfs(int x, int xp, int sum, int ff){//ff为容器元素和 
	if(xp == p && sum == n){
		if(ff > rear){
			rear = ff;
			ss = temp;
		}
		return;
	}
	if(xp > p || sum > n) return;
	if(x >= 1){
		//选择 
		temp.push_back(x);
		dfs(x, xp + 1, sum + pow(x, k), ff + x);
		//不选 
		temp.pop_back();
		dfs(x - 1, xp, sum , ff);
	}	
}
int main()
{
	scanf("%d%d%d", &n, &p, &k);
	if(k >= 2) m = (int)sqrt(1.0 * n);
	else m = n; 
	for(n1 = 1; n1 <= m; n1++){
		if(pow(n1, k) >= n) break;
	}
	dfs(n1, 0, 0, 0);//考虑到题目要求，从后往前输出 
	if(rear == -1) printf("Impossible\n");
	else{
//		printf("%d = ", n);
//		sort(ss.begin(), ss.end());
//		for(int i = ss.size() - 1; i > 0; i--) printf("%d^%d + ", ss[i], k);
//		printf("%d^%d", ss[0], k);
		printf("%d = %d^%d", n, ss[0], k);
		for(int i = 1; i < ss.size(); i++) printf(" + %d^%d", ss[i], k);
	}	
	return 0;
}
