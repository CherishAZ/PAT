//��̬�滮 
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
		flag[a[i]]++;//��¼ÿ��Ӳ�ҳ��ֵĴ��� 
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
	cout << "No Solution";//�ж����õ������ֵ�Ƿ����m����Ϊ������������ڼ�ֵ 
	else
	{
		int v = m, p = 0, q = 0;//v�Ǽ�¼ÿ��ѡ���˵�ֵ��p�������ƿո����
								//ÿ�����һ�ź����Ų����ٿ��ǣ�����ÿ��ѭ�����Լ�һ 
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
