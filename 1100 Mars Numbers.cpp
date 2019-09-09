#include <iostream>
#include <map>
#include <cstring>
using namespace std;

string s1[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string s2[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
map<string, int> mm;
string n2s[170];
void init()
{
	for(int i = 0; i < 13; i++){
		n2s[i] = s1[i];
		mm[s1[i]] = i;
		n2s[i * 13] = s2[i];
		mm[s2[i]] = i * 13;
	}
	for(int i = 1; i < 13; i++){
		for(int j = 1; j < 13; j++){
			string str = s2[i] + " " + s1[j];
			n2s[i * 13 + j] = str;
			mm[str] = i * 13 + j;
		}
	}
}
int str2int(string s)
{
	int k = 0;
	for(int i = 0; i < s.length(); i++){
		k = k * 10 + (s[i] - '0');
	}
	return k;
}
int main()
{
	init();
	int n, k;
	cin >> n;
	string t;
	getchar();
	for(int i = 0; i < n; i++){
		getline(cin ,t);
		if(t[0] >= '0' && t[0] <= '9') {
		k = str2int(t);
		cout << n2s[k] << endl;
		}
		else
		{
			cout << mm[t] << endl;
		}
	}
}
