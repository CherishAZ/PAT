//²¢²é¼¯È»ºó==2ÅÐ¶Ï£¬×¢Òâ<ÈÝÆ÷size£¬±ÜÃâ¶Î´íÎó 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int father[100100] = {0}, pair1[100100] = {0};
void init(){
	for(int i = 0; i < 100100; i++) father[i] = i;
}
int findFather(int v){
	if(father[v] == v) return v;
	else return findFather(father[v]);
}
void Union(int a, int b){
	int f1 = findFather(a);
	int f2 = findFather(b);
	if(f1 != f2){
		father[f2] = f1;
	}
}
int main()
{
	init();
	int n, m, t1, t2, t, index = 0, num = 0, j = 0;
	scanf("%d", &n);
	vector<int> ss;
	for(int i = 0; i < n; i++){
		scanf("%d%d", &t1, &t2);
		Union(t1, t2);
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d", &t);
		ss.emplace_back(t);
		pair1[father[t]]++;
	}
	sort(ss.begin(), ss.end());
	for(int i = 0; i < 100100; i++){
		if(pair1[i] == 1){
			num++;
		}
	}
	printf("%d\n", num);
	while(pair1[father[ss[j]]] != 1 && j < ss.size()) j++;//ÅÐ¶Ï£¬±ÜÃâ¶Î´íÎó 
	if(j < ss.size()) printf("%05d", ss[j++]);
	for(; j < ss.size(); j++){
		if(pair1[father[ss[j]]] == 1) printf(" %05d", ss[j]);
	}
	return 0;
}
