#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

struct node{
	string s;
	int x1, x2, x3;
	int y1, y2, y3;
}nn[10001];
int cmp1(node &n1, node &n2)
{
	if(n1.x1 != n2.x1)
	return n1.x1 < n2.x1;
	else if(n1.x2 != n2.x2)
	return n1.x2 < n2.x2;
	else
	return n1.x3 < n2.x3;
}
int cmp2(node &n1, node &n2)
{
	if(n1.y1 != n2.y1)
	return n1.y1 > n2.y1;
	else if(n1.y2 != n2.y2)
	return n1.y2 > n2.y2;
	else
	return n1.y3 > n2.y3;
}
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		string  t1, t2;
		cin >> nn[i].s >> t1 >> t2;
		sscanf(t1.c_str(), "%2d:%2d:%2d", &nn[i].x1, &nn[i].x2, &nn[i].x3);
		sscanf(t2.c_str(), "%2d:%2d:%2d", &nn[i].y1, &nn[i].y2, &nn[i].y3);
	}
	sort(nn, nn + n, cmp1);
	cout << nn[0].s << " ";
	sort(nn, nn + n, cmp2);
	cout << nn[0].s;
	return 0;
	
}
