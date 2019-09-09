#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ss;
int main()
{
	int n, p, v;
	cin >> n >> p;
	for(int i = 0; i < n; i++){
		cin >> v;
		ss.push_back(v);
	}
	sort(ss.begin(), ss.end());
	int ans = 1;
	for(int i = 0; i < ss.size(); i++){
		int j = upper_bound(ss.begin() + i + 1, ss.begin() + n, (long long)ss[i] * p) - ss.begin();
		ans = max(ans, j - i);
	}
	cout << ans;
	return 0;
}
