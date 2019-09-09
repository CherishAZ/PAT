//两个系数都是1000，所以乘出来的多项式的系数最大到2000 
#include <iostream>
using namespace std;

double a[1001] = {0}, c[2001] = {0};
int b[10] = {0};
int main()
{
	int n, m, k = 0;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int t1;
		double t2;
		cin >> t1 >> t2;
		b[i] = t1;
		a[t1] = t2;
	}
	cin >> m;
	for(int i = 0; i < m; i++)
	{
		int t1;
		double t2;
		cin >> t1 >> t2;
		for(int j = 0; j < n; j++)
		{
			c[t1 + b[j]] += t2 * a[b[j]];
		}
	}
	for(int i = 2000; i >= 0; i--)
	{
		if(c[i] != 0.0)
		k++;
	}
	cout << k;
	for(int i = 2000; i >= 0; i--)
	{
		if(c[i] != 0.0)
		printf(" %d %.1lf", i, c[i]);
	}
	return 0;
}
