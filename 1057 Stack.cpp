#include <iostream>
#include <cstring>
#include <stack>
#include <string>
using namespace std;
#define lowbit(i) ((i)&-(i))
const int M = 100010;

int c[M];
void update(int x, int v){
	for(int i = x; i < M; i += lowbit(i)){
		c[i] += v;
	} 
}
int getSum(int x){
	int sum = 0;
	for(int i = x; i > 0; i -= lowbit(i)){
		sum += c[i];
	}
	return sum;
}
void PeekMedian(int size){
	int l = 1, r = M, mid, k = (size + 1) / 2;
	while(l < r){
		mid = (l + r) / 2;
		if(getSum(mid) >= k) r = mid;
		else l = mid + 1;
	}
	cout << l << endl;
}
int main()
{
	int n, t;
	cin >> n;
	string s;
	stack<int> s1;
	for(int i = 0; i < n; i++){
		cin >> s;
		if(s == "Pop"){
			if(s1.empty()) cout << "Invalid" << endl;
			else{
				cout << s1.top() << endl;
				update(s1.top(), -1);
				s1.pop();
			}
		}else if(s == "Push"){
			cin >> t;
			s1.push(t);
			update(t, 1);	
		}else if(s == "PeekMedian"){
			int size = s1.size();
			if(size == 0) cout << "Invalid" << endl;
			else PeekMedian(size);
		}
	}
	return 0;
}
