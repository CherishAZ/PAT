#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int M = 100010;
#define lowbit(i) ((i)&(-i))

//20ms
int c[M] = {0};
void update(int x){
	for(int i = x; i < M; i += lowbit(i)){
		c[i] += 1;
	}	
}
int getsum(int x){
	int sum = 0;
	for(int i = x; i > 0; i -= lowbit(i)){
		sum += c[i];
	}
	return sum;
}
int main()
{
	int n, t;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &t);
		if(t == 0) continue;
		update(t);
	}
	int i, flag = 1;
	for(i = n; i >= 0; i--){
		if(i <= (n - getsum(i))){
			printf("%d", i);
			flag = 0;
			break;
		}
	}
	if(flag) cout << 0;
	return 0;
}
//53ms
//int main()
//{
//	int n, t;
//	cin >> n;
//	vector<int> ss;
//	for(int i = 0; i < n; i++){
//		cin >> t;
//		ss.emplace_back(t);
//	}
//	sort(ss.begin(), ss.end());
//	for(int i = ss.size() - 1; i >= 0; i--){
//		int temp = n - i - 1;
//		if(ss[temp] > i + 1){
//			cout << i + 1 ;
//			break;
//		} 
//	}
//	if(*ss.rbegin() <= 1) cout << "0";
//	return 0;
//}
