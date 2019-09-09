#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, d;
	vector<int> s;
	cin >> n >> d;
	if(n == 0)
	s.push_back(n);//注意特殊情况0 (题目中N>0),但应考虑到 
	while(n)//出现while(n)这种情况应注意0 
	{
		s.push_back(n % d);
		n /= d;
	}
	int flag = 1;
	for(int i = 0; i <= s.size() / 2 ; i++)
	{
		if(s[i] != s[s.size() - 1 - i])
		flag = 0; 
	}
	if(flag == 1) cout << "Yes" << endl;
	else cout << "NO" << endl;
	for(int i = s.size() - 1; i > 0; i--)
	cout << s[i] << " ";
	cout << *s.begin();

	return 0;
	
}
