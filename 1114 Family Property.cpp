#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
const int M = 10010;

struct estate{
	int num, area, family_members = 1;
	double avgsets, avgarea;
}ee[M];
int father[M];
bool isRoot[M] = {false};
int findFather(int x){
	int a = x;
	while(x != father[x]) x = father[x];
	if(a != father[a]){
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}
void Union(int a, int b){
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA < faB) swap(faA, faB);
	if(faA != faB){
		father[faA] = faB;
	}
}
int cmp(int a, int b){
	if(ee[a].avgarea != ee[b].avgarea) return ee[a].avgarea > ee[b].avgarea;
	else return a < b;
}
int main()
{
	set<int> ss, last;
	vector<int> avg;//最后平均 
	for(int i = 0; i <= M; i++) father[i] = i;
	int n;
	cin >> n;
	int id, fid, mid, k, cid, num , area;
	for(int i = 0; i < n; i++){
		cin >> id >> fid >> mid >> k;
		ss.insert(id);
		if(fid != -1){
			Union(id, fid);
			ss.insert(fid);
		} 
		if(mid != -1){
			Union(id, mid);
			ss.insert(mid);
		} 
		for(int i = 0; i < k; i++){
			cin >> cid;
			ss.insert(cid);
			Union(id, cid);
		}
		cin >> num >> area;
		ee[id].num = num;
		ee[id].area = area;
	}
	for(auto it:ss){
		int temp = findFather(it);
		if(it != temp){
			ee[temp].num += ee[it].num;
			ee[temp].area += ee[it].area;
			ee[temp].family_members += ee[it].family_members;
		}
		last.insert(temp);
	}
	cout << last.size() << endl;
	for(auto it:last){
		ee[it].avgsets = (double)ee[it].num / (double)ee[it].family_members;
		ee[it].avgarea = (double)ee[it].area / (double)ee[it].family_members;
		avg.emplace_back(it);
	}
	sort(avg.begin(), avg.end(), cmp);
	for(int i = 0; i < avg.size(); i++){
		printf("%04d %d %.3lf %.3lf\n", avg[i], ee[avg[i]].family_members, ee[avg[i]].avgsets, ee[avg[i]].avgarea);
	}
	return 0;
}
