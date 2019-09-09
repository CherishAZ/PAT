#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
const int M = 50010;

struct node{
	int val, num;
};
struct cmp{
	bool operator () (node n1, node n2){
		if(n1.num != n2.num) return n1.num > n2.num;
		else return n1.val < n2.val;
	}
};
int num1[M];
int main()
{
	set<node, cmp> st;
	int n, k, t;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%d", &t);
		int sum = 0;	
		if(i != 0){
			printf("%d:", t);
			for(auto it = st.begin(); it != st.end() && sum < k; it++){
				printf(" %d", it->val);
				sum++;
			}
			printf("\n");
		}
		auto it = st.find(node{t, num1[t]});
		if(it != st.end()) st.erase(it);
		num1[t]++;
		st.insert(node{t, num1[t]});
	}
	return 0;
}
