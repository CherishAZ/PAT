//��̬�滮,��Ҫһ��һ�������ַ�������2��3��4...����Ȼ�����û�м������dpֵ 
//ʱ�临�Ӷ�O(N^2) 
#include <iostream>
#include <string>
using namespace std;

int dp[1010][1010] = {0};
int main()
{
	string s;
	getline(cin, s);
	int ans = 1;//���Ĵ������ 
	for(int i = 0; i < s.length() - 1; i++)
	{
		dp[i][i] = 1;
		if(s[i] == s[i + 1])
		{
			dp[i][i + 1] = 1;
			ans = 2;//��ʱע�����Ϊ2
		}
	}
	dp[s.length() - 1] [s.length() - 1] = 1;
	
	for(int L = 3; L <= s.length(); L++)
	{
		for(int i = 0; i < s.length() - L + 1; i++)
		{
			int j = L + i - 1;//�ִ��Ҷ˵� 
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
