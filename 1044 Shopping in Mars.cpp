#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int M = 100010;

int sum[M];
int main()
{
	int n, m, t, nearS = 1000000000;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", &t);
		 sum[i + 1] = sum[i] + t;
	}
	for(int i = 1; i <= n; i++){
		int j = lower_bound(sum + i, sum + n + 1, sum[i - 1] + m ) - sum;
		if(sum[j]  - sum[i - 1] == m){
			nearS = m;
			break;
		}else if(j <= n && sum[j] - sum[i - 1] < nearS){
			nearS = sum[j] - sum[i - 1];
		}
	}
	for(int i = 1; i <= n; i++){
		int j = lower_bound(sum + i, sum + n + 1, sum[i - 1] + nearS) - sum;
		if(sum[j] - sum[i - 1] == nearS) printf("%d-%d\n", i, j);
	}
	return 0;
}
