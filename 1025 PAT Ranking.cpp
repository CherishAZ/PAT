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
	int n, m[101] = {0}, sum = 0, k = 0;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> m[i];
		sum += m[i];
		for(int j = 0; j < m[i]; j++)
		{
			cin >> nn1[k].name >> nn1[k].score;
			nn1[k].tag = i;
			k++;
		}
	}
	int rank[101] = {0}, d[101] = {0};
	int pos[101] = {0}, flag[101] = {0};
	fill(flag, flag + 101, -1);
	fill(rank, rank + 101, 1);
	sort(nn1, nn1 + k, cmp);
	for(int i = 0; i < k; i++)
	{
		if(flag[nn1[i].tag] == -1 )
		{
			pos[nn1[i].tag] = i;
			flag[nn1[i].tag] = 1;
		}
	}
	nn1[0].r1 = 1;
	nn1[0].r2 = 1;
	flag[nn1[0].tag] = 0;
	for(int i = 1; i < k; i++)
	{
		if(nn1[i].score != nn1[i - 1].score)
		nn1[i].r1 = i + 1;
		else
		nn1[i].r1 = nn1[i - 1].r1;
		
		if(nn1[i].score != nn1[pos[nn1[i].tag]].score)
		{
			nn1[i].r2 = ++rank[nn1[i].tag] + d[nn1[i].tag];
			rank[nn1[i].tag] += d[nn1[i].tag];
			d[nn1[i].tag] = 0;
		}
		else
		{
			if(flag[nn1[i].tag] == 1){
			nn1[i].r2 = rank[nn1[i].tag];
			flag[nn1[i].tag] = 0;//因为rank初始化为1，所以每个标记下的第一个d不加 
			}
			else{
			nn1[i].r2 = rank[nn1[i].tag];
			d[nn1[i].tag]++;//每个标记下前面相同的计数 
			}
		}
		
		pos[nn1[i].tag] = i;
	}
	cout << k << endl;
	for(int i = 0; i < k; i++)
	{
		cout << nn1[i].name << " " << nn1[i].r1 <<" " <<  nn1[i].tag << " " << nn1[i].r2 <<endl; 
	}
	return 0;
	
 } 
