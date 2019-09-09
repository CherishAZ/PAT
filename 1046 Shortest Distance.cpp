#include <iostream>
using namespace std;

int a[100001], sum[100001];
int main()
{
	int n, m;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum[i] = a[i] + sum[i - 1];
	}
	int ss = sum[n];
	cin >> m;
	for(int i = 0; i < m; i++)
	{
		int p, q, dis = 0;
		cin >> p >> q;
//		while( ((p - 1) % n + 1) != q)
//		{
//			dis += a[(p - 1) % n + 1];
//			p++;
//		}
//³¬Ê±
 		if(q > p) dis = sum[q - 1] - sum[p - 1];
 		else dis = sum[p - 1] - sum[q - 1];
		int dis1 = ss - dis;
		cout << min(dis, dis1) << endl;
	}
	return 0;
}
