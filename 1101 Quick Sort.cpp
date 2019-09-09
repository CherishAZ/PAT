#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int M = 100010;

int a[M], n;
int main()
{
	int l_max = 0;
	vector<int> s, ans;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		s.push_back(a[i]);
	}
	sort(s.begin(), s.end());
	for(int i = 0; i < n; i++){
		int flag = 0;
		if(a[i] > l_max) l_max = a[i];
		if(a[i] == s[i]){
			flag = 1;
			if(s[i] != l_max) flag = 0;
		}
		if(flag) ans.push_back(s[i]);
	}
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i];
		if(i != ans.size() - 1) cout << " ";
	}
	cout << endl;
	return 0;
}
