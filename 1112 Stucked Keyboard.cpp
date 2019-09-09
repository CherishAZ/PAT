#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int flag[256] = {0};
int main()
{
	int k, rank = 2;
	string s;
	cin >> k;
	getchar();
	map<int, char> cc;
	vector<int> ss;
	getline(cin, s);
	for(int i = 0; i < s.length(); i++){
		int j = i, num = 1;
		while(s[j] == s[j + 1] && j < s.length() - 1){
			num++;
			j++;
		}
		if(num % k == 0 && flag[s[i]] != -1 ){
			if(flag[s[i]] == 0){
				flag[s[i]] = rank;
				cc[rank] = s[i];
				rank++;
			}	
			i = j;	
		}else flag[s[i]] = -1;
	}
	for(int i = 0; i < 256; i++) if(flag[i] > 1) ss.push_back(flag[i]);
	sort(ss.begin(), ss.end());
	for(int i = 0; i < ss.size(); i++) cout << cc[ss[i]];
	cout << endl;
	for(int i = 0; i < s.length(); i++){
		cout << s[i];
		if(flag[s[i]] > 1) i += k - 1;
	}
	return 0;
}
/*
3
caseee1___thiiis_iiisss_a_teeeeeest
*/
