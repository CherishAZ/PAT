//动态规划 
#include <iostream> 
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 10010;
int A[maxn], dp[maxn], s[maxn] = {0};
int main()
{
	int n, flag = 0;
	vector<int> ss;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
		if(A[i] >= 0)
		flag = 1;
	}
	if(flag == 0)
	{
		cout << "0" << " " <<  A[0] << " " << A[n - 1];
		return 0;
	}
	dp[0] = A[0];
	int k = 0;
	for(int i = 1; i < n; i++)
	{
		dp[i] = max(A[i], dp[i - 1] + A[i]);
		if(dp[i] > dp[k])
		k = i;
		if(dp[i - 1] + A[i] > A[i]){
			s[i] = s[i - 1];//s[i]记录最长序列开始的位置 
		}
		else
		{
			s[i] = i;
		}
	}
	cout << dp[k] << " " << A[s[k]] <<  " " << A[k];
	return 0;
}
