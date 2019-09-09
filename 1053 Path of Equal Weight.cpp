#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, weight;
vector<int> s1;
bool flag[110] = {false};//еп╤ор╤вс╫з╣Ц 
struct tree{
	int w;
	vector<int> child;
}tt[110];

int cmp(int a, int b){
	return tt[a].w > tt[b].w;
}
void dfs(int sum, int index){
	if(sum == weight && !flag[index]){
		for(int i = 0; i < s1.size(); i++)
		printf("%d ", tt[s1[i]].w);
		printf("%d\n", tt[index].w); 
		return;
	} 
	if(sum > weight) return;
	s1.push_back(index);
	for(int i = 0; i < tt[index].child.size(); i++){
		int temp = tt[index].child[i];
		dfs(sum + tt[temp].w, temp);
	}
	s1.pop_back();
}
int main()
{
	int temp1, num, temp2;
	scanf("%d%d%d", &n, &m, &weight);
	for(int i = 0; i < n; i++) scanf("%d", &tt[i].w);
	for(int i = 0; i < m; i++){
		scanf("%d%d", &temp1, &num);
		flag[temp1] = true;
		for(int j = 0; j < num; j++){
			scanf("%d", &temp2);
			tt[temp1].child.push_back(temp2);
		}
		sort(tt[temp1].child.begin(), tt[temp1].child.end(), cmp);
	}
	dfs(tt[0].w, 0);
	return 0;
} 

/*
20 9 24
10 2 4 3 5 10 2 18 9 7 2 2 1 3 12 1 8 6 2 2
00 4 01 02 03 04
02 1 05
04 2 06 07
03 3 11 12 13
06 1 09
07 2 08 10
16 1 15
13 3 14 16 17
17 2 18 19
*/
