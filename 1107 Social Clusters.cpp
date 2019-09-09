#include <iostream>
#include <algorithm>
using namespace std;

int father[1010], num[1010], course[1010] = {0};
int init(int n){
	for(int i = 1; i <= n; i++) father[i] = i;
	
}
int cmp(int a, int b){
	return a > b;
}
int findFather(int x){
	int a = x;
	while(x != father[x]) x = father[x];
	while( a != father[a]){
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}
void Union(int a, int b){
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB) father[faA] = faB;
}
int main()
{
	int n, t1, t2, ans = 0;
	scanf("%d", &n);
	init(n);
	for(int i = 1; i <= n; i++){
		scanf("%d:", &t1);
		for(int j = 0; j < t1; j++){
			scanf("%d", &t2);
			if(course[t2] == 0) course[t2] = i;
			Union(i, findFather(course[t2]));
		}
	}
	for(int i = 1; i <= n; i++) num[findFather(i)]++;
	for(int i = 1; i <= n; i++)
	if(num[i] > 0) ans++;
	printf("%d\n", ans);
	sort(num + 1, num + n + 1, cmp);
	for(int i = 1; i <= ans; i++){
		printf("%d", num[i]);
		if(i != ans) printf(" ");
	}
	return 0;
}
