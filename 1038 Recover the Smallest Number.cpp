#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> ss;
int cmp(string s1, string s2){
	return s1 + s2 < s2 + s1;
}
int main()
{
	int n, j = 0;
	cin >> n;
	string s, t;
	for(int i = 0; i < n; i++){
		cin >> s;
		ss.emplace_back(s);
	}
	sort(ss.begin(), ss.end(), cmp);
	for(int i = 0; i < ss.size(); i++) t += ss[i];
	while(t[j] == '0') j++;
	if(j == t.size()) cout << 0;
	else cout << t.substr(j);
	return 0;
}
