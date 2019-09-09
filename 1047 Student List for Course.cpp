#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

char ss1[40010][5];
vector<int> ss[2510];
int cmp(int a, int b)
{
	return strcmp(ss1[a], ss1[b]) < 0;
}
int main()
{
	int n, m, t, t1;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%s %d", ss1[i], &t);
		for(int j = 0; j < t; j++){
			scanf("%d", &t1);
			ss[t1].push_back(i);
		}
	}
	for(int i = 1; i <= m; i++){
		printf("%d %d\n", i, ss[i].size());
		sort(ss[i].begin(), ss[i].end(), cmp);
		for(int j = 0; j < ss[i].size(); j++) printf("%s\n", ss1[ss[i][j]]);
	}
	return 0;
 } 
/*
10 5
ZOE1 2 4 5
ANN0 3 5 2 1
BOB5 5 3 4 2 1 5
JOE4 1 2
JAY9 4 1 2 5 4
FRA8 3 4 2 5
DON2 2 4 5
AMY7 1 5
KAT3 3 5 4 2
LOR6 4 2 4 1 5
*/
