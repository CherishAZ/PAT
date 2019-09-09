//动态规划 LCS(最长公共子序列) 
#include <iostream>
using namespace std;

int dp[210][10010] = {0}, b[10010], a[210];

int main()
{
	int n, m, k, x;
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	cin >> a[i];
	cin >> k;
	for(int i = 1; i <= k; i++)
	cin >> b[i];
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= k; j++)
		{
			if(a[i] == b[j])
			dp[i][j] = max(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
			else
			dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
		}
	}
	cout << dp[m][k];
	return 0;
 } 
