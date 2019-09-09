#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int n, m = 10000001;
	cin >> n;
	vector<string> ss;
	getchar();
	for(int i = 0; i < n; i++)
	{	
		string s;
		getline(cin, s); 
		int len =  s.length();
		if(len < m) m = len;
		ss.push_back(s);		
	}
	int j = 1, flag = 1;
	string t, t1;
	for(; j <= m; j++){
		t = ss[0].substr(ss[0].length() - j);
		for(int i = 1; i < ss.size(); i++)
		{
			t1 = ss[i].substr(ss[i].length() - j);
			if(t1 != t)
			{
				flag = 0;
				break;
			}
		}
		if(flag == 0) break;
	}
	if (j == m + 1)
	cout << ss[0].substr(ss[0].length() - m);
	else{
	if(j > 1)
	cout << ss[0].substr(ss[0].length() - j + 1);
	else
	cout << "nai";
	}
	return 0;
}

