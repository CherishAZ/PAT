#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct stu{
	string name;
	int r1, r2, tag, score;
}nn1[30001];

int cmp(stu &s1, stu &s2)
{
	if(s1.score != s2.score) return s1.score > s2.score;
	else return s1.name < s2.name;
}
int main()
{
	int n, m, k = 0;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> m;
		for(int j = 0; j < m; j++)
		{
			cin >> nn1[k].name >> nn1[k].score;
			nn1[k].tag = i;
			k++;
		}
		sort(nn1 + k - m, nn1 + k, cmp);
		nn1[k - m].r2 = 1;
		for(int l = k - m + 1; l < k; l++)
		{
			if( nn1[l].score != nn1[l - 1].score)
			nn1[l].r2 = l - k + m + 1;
			else
			nn1[l].r2 = nn1[l - 1].r2;
		}
	}
	sort(nn1, nn1 + k, cmp);

	nn1[0].r1 = 1;
	for(int i = 1; i < k; i++)
	{
		if(nn1[i].score != nn1[i - 1].score)
		nn1[i].r1 = i + 1;
		else
		nn1[i].r1 = nn1[i - 1].r1;
	}
	cout << k << endl;
	for(int i = 0; i < k; i++)
	{
		cout << nn1[i].name << " " << nn1[i].r1 <<" " <<  nn1[i].tag << " " << nn1[i].r2 <<endl; 
	}
	return 0;
	
 } 
