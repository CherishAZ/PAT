#include <iostream>
#include <unordered_set>
#include <vector>
#include <set>
#include <cstring>
using namespace std;
const int M = 10010;

int m, n, v[M];
int main()
{
	set<int> st;
	cin >> m >> n;
	for(int i = 0; i < n; i++){
		cin >> v[i];
		st.insert(v[i]);
	}
	int t1, t2, flag1, flag2, ans;
	for(int i = 0; i < m; i++){
		flag1 = 1, flag2 = 1;
		cin >> t1 >> t2;
		if(st.find(t1) == st.end()) flag1 = 0;
		if(st.find(t2) == st.end()) flag2 = 0;
		if(flag1 == 0 && flag2 == 0) printf("ERROR: %d and %d are not found.\n", t1, t2);
		if(flag1 == 1 && flag2 == 0) printf("ERROR: %d is not found.\n", t2);
		if(flag1 == 0 && flag2 == 1) printf("ERROR: %d is not found.\n", t1);
		if(flag1 == 1 && flag2 == 1){
			for(int i = 0; i < n; i++){
				if((t1 >= v[i] && v[i] >= t2) || (t2 >= v[i] && v[i] >= t1)){
					ans = v[i];
					break;
				}
			}
			if(t1 == ans || t2 == ans) printf("%d is an ancestor of %d.\n", ans, ans == t1? t2 : t1);
			else printf("LCA of %d and %d is %d.\n", t1, t2, ans);
		}
	}
	return 0;
}
