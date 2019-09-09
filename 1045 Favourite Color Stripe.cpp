//动态规划 LIS(最长不下降子序列) 
#include <iostream>
using namespace std;

int dp[10010] = {0}, s[10010], like[210] = {0};

int main()
{
	int n, m, k, x;
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> x;
		like[x] = i + 1;
	}
	cin >> k;
	for(int i = 0; i < k; i++)
	cin >> s[i];
	int ans = -1;
	for(int i = 0; i < k; i++)
	{
		if(like[s[i]] > 0)//判断是否为喜欢颜色才让dp[i] = 1 
		dp[i] = 1;
		for(int j = 0; j < i; j++)
		{
			int flag = 0;
			if(like[s[j]] <= like[s[i]] && like[s[i]] > 0)
			flag = 1;
			if(flag == 1 && dp[j] + 1 > dp[i])
			dp[i] = dp[j] + 1;
		}
		ans = max(dp[i] , ans);
	}
	cout << ans;
	return 0;
 } 
