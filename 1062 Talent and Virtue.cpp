#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int M = 100010;
int n, l, h;
struct people{
	int id, v, t, sum;
}pp[M];
int cmp(people p1, people p2){
	if(p1.sum != p2.sum) return p1.sum > p2.sum;
	else if(p1.v != p2.v) return p1.v > p2.v;
	else if(p1.t != p2.t) return p1.t > p2.t;
	else return p1.id < p2.id;
}
int main()
{
	vector<people> ss[5];
	scanf("%d%d%d", &n, &l, &h);
	for(int i = 0; i < n; i++){
		scanf("%d%d%d", &pp[i].id, &pp[i].v, &pp[i].t);
		pp[i].sum = pp[i].v + pp[i].t;
	}
	sort(pp, pp + n, cmp);
	for(int i = 0; i < n; i++){
		if(pp[i].t >= h && pp[i].v >= h) ss[0].emplace_back(pp[i]);
		else if(pp[i].v >= h && pp[i].t >= l) ss[1].emplace_back(pp[i]);
		else if(pp[i].t >= l && pp[i].v >= pp[i].t) ss[2].emplace_back(pp[i]);
		else if(pp[i].v >= l && pp[i].t > pp[i].v) ss[3].emplace_back(pp[i]);
	}
	printf("%d\n", ss[0].size() + ss[1].size() + ss[2].size() + ss[3].size());
	for(int i = 0; i < 4; i++)
	for(auto it : ss[i]) printf("%08d %d %d\n", it.id, it.v, it.t);
	return 0;
}
