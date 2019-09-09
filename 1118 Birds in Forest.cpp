#include <iostream>
#include <set>
using namespace std;
const int M = 10010;

int father[M], a[M], flag[M] = {0};
int findFather(int x){
	int a = x;
	while(x != father[x]){
		x = father[x];
	}
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
	if(faA != faB){
		father[faB] = faA;
	}
}

int main()
{
	for(int i = 0; i < M; i++) father[i] = i;
	int n, m, k, b1, b2, max_num = 0, num = 0;
	cin >> n;
	set<int> ss;
	for(int i = 0; i < n; i++){
		cin >> m;
		for(int j = 0; j < m; j++){
			cin >> a[j];
			ss.insert(a[j]);
		}
		for(int j = 0; j < m; j++) Union(a[0], a[j]);
	}
	for(auto it:ss) flag[findFather(it)]++;
	for(auto it:ss) if(flag[it] > 0) num++;
	cout << num << " " << ss.size() << endl;
	cin >> k;
	for(int i = 0; i < k; i++){
		cin >> b1 >> b2;
		if(findFather(b1) == findFather(b2)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}
