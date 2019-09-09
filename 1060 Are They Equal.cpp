#include <iostream>
#include <string>
using namespace std;

int n;
string sim(string s, int &e)
{
	int k = 0;
	while(s.length() > 0 && s[0] == '0')
	s.erase(s.begin());
	if(s[0] == '.')
	{
		s.erase(s.begin());
		while(s.length() > 0 && s[0] == '0')
		{
			s.erase(s.begin());
			e--;			
		}
	}
	else
	{
		int pos = s.find('.');
		if(pos != string::npos )
		{
			k = pos;
			e = pos;
		}
		else
		{
			k = s.length();
			e = s.length();
		}
	
	if(k < s.length())
	s.erase(s.find('.'));
	}
	if(s.length() == 0)
	e = 0;
	int num = 0;
	k = 0;
	string res;
	while(num < n)
	{
		if(k < s.length()) res += s[k++];
		else
		res += '0';
		num++;
	}
	return res;
	
}
int main()
{
	
	string a, b;
	cin >> n >> a >> b;
	int e1 = 0, e2 = 0;
	string a1, b1;
	a1 = sim(a, e1);
	b1 = sim(b, e2);
	if( a1 == b1 && e1 == e2)
	printf("YES 0.%s*10^%d", a1.c_str(), e1);
	else
	printf("NO 0.%s*10^%d 0.%s*10^%d", a1.c_str(), e1, b1.c_str(), e2);
	
	return 0;
}
