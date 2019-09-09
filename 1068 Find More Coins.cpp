//动态规划 
#include <iostream>
#include <algorithm>
using namespace std;

int a[10010] = {0}, dp[10010] = {0}, choice[10010][110], flag[10010] = {0};
int cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		flag[a[i]]++;//记录每种硬币出现的次数 
	}
	sort(a, a + n, cmp);
	for(int i = 0; i < n; i++)
	{
		for(int v = m; v >= a[i]; v--)
		{
			if(dp[v] > dp[v - a[i]] + a[i])
			{
				choice[i][v] = 0;
			}
			else
			{
				dp[v] = dp[v - a[i]] + a[i];
				choice[i][v] = 1;
			}
		}
	}
	if(dp[m] != m)
	cout << "No Solution";//判断最后得到的最大值是否等于m，因为这题的重量等于价值 
	else
	{
		int v = m, p = 0, q = 0;//v是记录每次选择了的值，p用来控制空格输出
								//每次输出一排后，这排不用再考虑，所以每次循环可以减一 
		for(int i = n - 1 - q; i >= 0; i--){
		while(choice[i][v] == 1 && flag[a[i]])
		{
			if(p) cout << " ";
			cout << a[i];
			v -= a[i];
			flag[a[i]]--;
			p = 1;
			q++;
			continue;
		}
		}
	}
	return 0;
}
