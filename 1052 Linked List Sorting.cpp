#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int data[100010], nn[100010];
int cmp(int a, int b){
	return data[a] < data[b];
}
int main()
{
	int n, add, t;
	scanf("%d %d", &n, &add);
	vector<int> ss;
	for(int i = 0; i < n; i++){
		scanf("%d", &t); 
		scanf("%d %d", &data[t], &nn[t]);
	}
	while(add != -1){
		ss.push_back(add);
		add = nn[add];
	}
	sort(ss.begin(), ss.end(), cmp);
	if(ss.size() == 0){
		printf("0 -1");
		return 0; 
	}//对于没有元素，输出0 -1 
	else printf("%d %05d\n", ss.size(), *ss.begin());
	for(int i = 0; i < ss.size() - 1; i++){
		printf("%05d %d %05d\n",ss[i], data[ss[i]], ss[i + 1]);
	}
	printf("%05d %d -1", *ss.rbegin(), data[*ss.rbegin()]);
	return 0;
}

