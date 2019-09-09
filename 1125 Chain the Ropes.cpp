#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, t;
	cin >> n;
	vector<int> ss;
	for(int i = 0; i < n; i++){
		cin >> t;
		ss.emplace_back(t);
	}
	sort(ss.begin(), ss.end());
	double sum = (ss[0] + ss[1]) * 1.0 / 2;
	for(int i = 2; i < ss.size(); i++){
		sum += ss[i];
		sum /= 2;
	}
	cout << (int)sum;
	return 0;
}
