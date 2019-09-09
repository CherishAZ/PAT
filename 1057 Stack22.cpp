#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
const int M = 100010;
const int sqrN = 316;

stack<int> st;
int block[sqrN];
int table[M];

void Push(int x){
	st.push(x);
	block[x / sqrN]++;
	table[x]++;
}
void Pop(){
	int x = st.top();
	printf("%d\n", x);
	block[x / sqrN]--;
	table[x]--;
	st.pop();
}
void peekMedian(int k){
	int sum = 0;
	int idx = 0;
	while(sum + block[idx] < k) sum += block[idx++];
	int num = idx * sqrN;
	while(sum + table[num] < k) sum += table[num++];
	printf("%d\n", num);
}
int main()
{
	int x, query;
	memset(block, 0, sizeof(block));
	memset(table, 0, sizeof(table));
	char cmd[20]; 
	scanf("%d", &query);
	for(int i = 0; i < query; i++){
		scanf("%s", cmd);
		if(strcmp(cmd, "Push") == 0){
			scanf("%d", &x);
			Push(x);
		}else if(strcmp(cmd, "Pop") == 0){
			if(st.empty()){
				printf("Invalid\n");
			}else Pop();
		}
		else{
			if(st.empty()) printf("Invalid\n");
			else{
				int k = st.size();
				if(k % 2) k = (k + 1) / 2;
				else k /= 2;
				peekMedian(k);
			}
		}
	}
	return 0;
}
