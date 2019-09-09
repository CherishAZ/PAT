//倒着找，若有重复会等到它的第一次出现才push_back，然后倒着输出 
#include <bits/stdc++.h>
using namespace std;
int main()
{
	char str[2][81];
	cin>> str[0] >> str[1];
	char *p = str[0], *q = str[1];
	vector<char> ch,ch1;
	for (int i = 0,j = 0; i < strlen(p) ;i++)
	{
		if( p[i] != q[j]) ch.push_back (p[i]);
		else j++;
	}
	for (int i = 0; i < ch.size(); i++)
	{
		if(ch[i] >= 'a' && ch[i] <= 'z')
		ch[i] = ch[i] - 32;
	}
	for( int i = ch.size()-1; i >= 0; i--)
	{
		int flag = 1;
		for( int j = i - 1 ; j >= 0 ; j--)
		if(ch[j] == ch[i]) flag = 0;
		if(flag) ch1.push_back(ch[i]);
	}
	
	for (int i = ch1.size()-1;i >= 0; i--)
	cout << ch1[i];	
	return 0; 
}
	
