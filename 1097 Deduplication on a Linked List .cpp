#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int data[100010], nn[100010], flag[100010];
int main()
{
	int n, add, t;
	vector<int> ss, rr;
	scanf("%d %d", &add, &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &t);
		scanf("%d %d",&data[t], &nn[t]); 
	}
	while(add != -1){
		if(flag[abs(data[add])] == 0) {
			ss.push_back(add);
			flag[abs(data[add])] = 1;
		}
		else rr.push_back(add);	
		add = nn[add];
	}	
	for(int i = 0; i < ss.size() - 1; i++) printf("%05d %d %05d\n", ss[i], data[ss[i]], ss[i + 1]);
	if(ss.size() != 0) printf("%05d %d -1\n", *ss.rbegin(), data[*ss.rbegin()]);
	if(rr.size() == 0) return 0;//考虑rmove容器可能没有元素，有必要判断，否则段错误 
	else{
	for(int i = 0; i < rr.size() - 1; i++) printf("%05d %d %05d\n", rr[i], data[rr[i]], rr[i + 1]);
	printf("%05d %d -1\n", *rr.rbegin(), data[*rr.rbegin()]);
	}
	return 0;
 } 
