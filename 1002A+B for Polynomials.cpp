#include <iostream>
using namespace std;

double s[1001], s1[1001], s2[1001];
int main()
{
	int m, n;
	cin >> m;
	for(int i = 0; i < m; i++)
	{
		int a;
		double b;
		cin >> a >> b;
		s1[a] = b;
	}
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int a;
		double b;
		cin >> a >> b;
		s2[a] = b;
	}
	int num = 0;
	for(int i = 1000; i >= 0; i--)
	{
		s[i] = s1[i] + s2[i];
		if(s[i] != 0)
		{
			num++;
		}
	}
	cout << num;
	for(int i = 1000; i >= 0; i--)
	{
		if(s[i] != 0)
		{
			printf(" %d %.1lf", i, s[i]);
		}
	}
	return 0;
}
