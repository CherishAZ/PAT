#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> c1, c2, p1, p2;
int cmp(int a, int b){
	return a > b;
}
int main()
{
	int nc, np, t;
	scanf("%d", &nc);
	for(int i = 0; i < nc; i++){
		scanf("%d", &t);
		if(t > 0) c1.emplace_back(t);
		else if(t < 0) c2.emplace_back(t);
	}
	scanf("%d", &np);
	for(int i = 0; i < np; i++){
		scanf("%d", &t);
		if(t > 0) p1.emplace_back(t);
		else if(t < 0) p2.emplace_back(t);
	}
	sort(c1.begin(), c1.end(), cmp);
	sort(p1.begin(), p1.end(), cmp);
	sort(c2.begin(), c2.end());
	sort(p2.begin(), p2.end());
	int ans = 0, pos = 0, pos1 = 0;
	for(; pos < c1.size() && pos < p1.size(); pos++) ans += c1[pos] * p1[pos];
	for(; pos1 < c2.size() && pos1 < p2.size(); pos1++) ans += c2[pos1] * p2[pos1];
	printf("%d", ans);
	return 0;
}
