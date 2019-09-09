#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<string> ss;
	for(int i = 0; i < n; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		int flag = 0;
		for(int j = 0; j < s2.length(); j++)
		{
			if(s2[j] == '1') 
			{
				flag = 1;
				s2[j] = '@';
			}
			if(s2[j] == '0') 
			{
				flag = 1;
				s2[j] = '%';
			}
			if(s2[j] == 'l') 
			{
				flag = 1;
				s2[j] = 'L';
			}
			if(s2[j] == 'O') 
			{
				flag = 1;
				s2[j] = 'o';
			}
		 }
		 if(flag == 1)
		 ss.push_back(s1 + " " + s2 );
	}
	if(ss.size() != 0)
	{
		cout << ss.size() << endl;
		for(int i = 0; i < ss.size(); i++)
		cout << ss[i] << endl;
	}
	if(ss.size() == 0 && n == 1)
	cout << "There is 1 account and no account is modified";
	if(ss.size() == 0 && n > 1)
	cout << "There are "<< n << " accounts and no account is modified";
}
