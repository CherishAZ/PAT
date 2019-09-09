#include <iostream>
#include <set>
#include <vector>
using namespace std;

set<set<string> > ss(2500);
int main()
{
	int n, k, t1, t2;
	cin >> n >> k;
	string t;
	vector<int> s;
	for(int i = 0; i < k; i++){
		cin >> t1 >> t2;
		for(int j = 0; j < t2; j++){
			cin >> t;
			ss[t1].insert(t);
		}
	}
	for(int i = 0; i < n; i++){
		cin >> t;
		for(int j = 1; j <= k; j++){
			set<string> ::iterator it = ss[j].find(t);
			if(it != ss[j].end()) s.push_back(j);
		cout << t << " " << s.size();
		for(int ii = 0; ii < s.size(); ii++) cout << " " << s[ii];
		s.clear();
	}
	return 0;
}
