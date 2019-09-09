//前序位置从0开始直到n，
//如果出现当前位置的元素在中序遍历的位置介于t1,t2之间或为其中一个元素，则找到LCA 
#include <iostream>
#include <set>
#include <map>
using namespace std;
const int M = 10010;

int m, n, in[M], pre[M];
map<int, int> mm;
//void lca(int inl, int inr, int preRoot, int t1, int t2){
//	if(inl > inr) return;
//	int inroot = mm[pre[preRoot]], pos1 = mm[t1], pos2 = mm[t1];
//	if(pos1 < inroot && pos2 < inroot) lca(inl, inroot - 1, preRoot + 1, t1, t2);
//	else if((pos1 < inroot && inroot < pos2) || (pos2 < inroot && inroot < pos1))
//	printf("LCA of %d and %d is %d.\n", t1, t2, in[inroot]);
//	else if(pos1 > inroot && pos2 > inroot) lca(inroot + 1, inr, preRoot + 1 + inroot - inl, t1, t2);
//	else if(pos1 == inroot) printf("%d is an ancestor of %d.\n", t1, t2);
//	else if(pos2 == inroot) printf("%d is an ancestor of %d.\n", t2, t1);
//}
int main()
{
	set<int> st;
	cin >> m >> n;
	for(int i = 0; i < n; i++){
		cin >> in[i];
		mm[in[i]] = i;
		st.insert(in[i]);
	} 
	for(int i = 0; i < n; i++) cin >> pre[i];
	int t1, t2, flag1, flag2;
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
				int inroot = mm[pre[i]], pos1 = mm[t1], pos2 = mm[t2];
				if((pos1 < inroot && inroot < pos2) || (pos2 < inroot && inroot < pos1)){
					printf("LCA of %d and %d is %d.\n", t1, t2, in[inroot]);
					break;
				}
				else if(pos1 == inroot){
					printf("%d is an ancestor of %d.\n", t1, t2);
					break;
				} 
				else if(pos2 == inroot){
					printf("%d is an ancestor of %d.\n", t2, t1);
					break;
				} 
			}
		}
		// lca(0, n - 1, 0, t1, t2);
	}
	return 0;
}
