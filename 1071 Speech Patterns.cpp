#include <iostream>
#include <map>
using namespace std;

void init(string &ss)
{
	for(int i = 0; i < ss.length(); i++){
		if(ss[i] >= 'A' && ss[i] <= 'Z') 
		ss[i] += 32;
	}
}
int flag(char c)
{
	if((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) return 1;
	else return 0;
}
int main()
{
	int p = 0, p1 = 0, num = 0;//p记录第一有效字母开始的位置，p1记录第一个无效符号的位置 
	string s, s1, s2;
	getline(cin, s);
	init(s);
	map<string, int> mm;
	for(int i = 0; i < s.length(); i++){
		while(flag(s[i]) == 0 && i < s.length()) i++;
		p = i;
		while(flag(s[i]) == 1 && i < s.length()) i++;
		p1= i;
		s1 = s.substr(p, p1 - p);
		mm[s1]++;
		if(mm[s1] > num)
		{
			num = mm[s1];
			s2 = s1;
		}
			 	
	}	
	cout << s2 << " " << num;
	return 0;
}
