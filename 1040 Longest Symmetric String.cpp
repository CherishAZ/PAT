//动态规划,需要一步一步，从字符串长度2到3到4...，不然会出现没有计算过的dp值 
//时间复杂度O(N^2) 
#include <iostream>
#include <string>
using namespace std;

int dp[1010][1010] = {0};
int main()
{
	string s;
	getline(cin, s);
	int ans = 1;//回文串最长长度 
	for(int i = 0; i < s.length() - 1; i++)
	{
		dp[i][i] = 1;
		if(s[i] == s[i + 1])
		{
			dp[i][i + 1] = 1;
			ans = 2;//此时注意更新为2
		}
	}
	dp[s.length() - 1] [s.length() - 1] = 1;
	
	for(int L = 3; L <= s.length(); L++)
	{
		for(int i = 0; i < s.length() - L + 1; i++)
		{
			int j = L + i - 1;//字串右端点 
			if(s[i] == s[j] && dp[i + 1][j - 1] == 1)
			{
				dp[i][j] = 1;
				ans = L;
			}
		}
	}
	cout << ans;
	return 0;
}
