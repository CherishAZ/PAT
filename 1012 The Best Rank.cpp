#include <iostream>
#include <algorithm>
using namespace std;

struct stu{
	string id;
	int c, m, e, a, r1, r2, r3, r4;
}nn[2010];
int cmp1(stu nn1, stu nn2)
{
	return (nn1.c != nn2.c) ? (nn1.c > nn2.c) : (nn1.id < nn2.id);
}
int cmp2(stu nn1, stu nn2)
{
	return (nn1.m != nn2.m) ? nn1.m > nn2.m : (nn1.id < nn2.id);
}
int cmp3(stu nn1, stu nn2)
{
	return (nn1.e != nn2.e) ? nn1.e > nn2.e : (nn1.id < nn2.id);
}
int cmp4(stu nn1, stu nn2)
{
	return (nn1.a != nn2.a) ? (nn1.a > nn2.a) : (nn1.id < nn2.id);
}
int main()
{
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> nn[i].id >> nn[i].c >> nn[i].m >> nn[i].e;
		nn[i].a = (nn[i].c + nn[i].m + nn[i].e) / 3;
	}
	sort(nn, nn + n, cmp1);
	nn[0].r1 = 1;
	for(int i = 1; i < n; i++)
	{
		if(nn[i].c == nn[i - 1].c)
		nn[i].r1 = nn[i - 1].r1;
		else
		nn[i].r1 = i + 1;
	}
	
	sort(nn, nn + n, cmp2);
	nn[0].r2 = 1;
	for(int i = 1; i < n; i++)
	{
		if(nn[i].m == nn[i - 1].m)
		nn[i].r2 = nn[i - 1].r2;
		else
		nn[i].r2 = i + 1;
	}
	
	sort(nn, nn + n, cmp3);
	nn[0].r3 = 1;
	for(int i = 1; i < n; i++)
	{
		if(nn[i].e == nn[i - 1].e)
		nn[i].r3 = nn[i - 1].r3;
		else
		nn[i].r3 = i + 1;
	}
	
	sort(nn, nn + n, cmp4);
	nn[0].r4 = 1;
	for(int i = 1; i < n; i++)
	{
		if(nn[i].a == nn[i - 1].a)
		nn[i].r4 = nn[i - 1].r4;
		else
		nn[i].r4 = i + 1;
	}
	for(int j = 0; j < m; j++)
	{
		string s;
		cin >> s;
		int i = 0;
		for(; i < n; i++)
		{
			if( s == nn[i].id)
			{
				int rank = min(min(nn[i].r1, nn[i].r2), min(nn[i].r3, nn[i].r4));
				if(rank == nn[i].r4) {cout << rank << " " << "A" << endl; break;}
				if(rank == nn[i].r1) {cout << rank << " " << "C" << endl; break;}
				if(rank == nn[i].r2) {cout << rank << " " << "M" << endl; break;}
				if(rank == nn[i].r3) {cout << rank << " " << "E" << endl; break;}
			}	
		}
		if(i == n) cout << "N/A" << endl; 
	}

	return 0;
}
