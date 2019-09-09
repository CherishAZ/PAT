#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int data[100005];
int next1[100005];
int main()
{
	int t, start, n, k;
	vector<int> ss;
	cin >> start >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> t;
		cin >> data[t] >> next1[t];
	}
	while(start != -1){
		ss.push_back(start);
		start = next1[start];
	}
	 
	int j = 1, sum = ss.size();
	while(j <= sum / k){
		reverse(ss.begin() + (j - 1) * k, ss.begin() + j * k);
		j++;
	}
	for(int i = 0; i < ss.size() - 1; i++)	printf("%05d %d %05d\n", ss[i], data[ss[i]], ss[i + 1]);
	printf("%05d %d -1", *ss.rbegin(), data[*ss.rbegin()]);
	return 0;
} 

