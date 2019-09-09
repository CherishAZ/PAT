#include <iostream>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int i = 1, len = s.length();
	while( len > 3 * i)
	i++;
	int j = len - 2 * i + 2;
	
	for(int m = 0; m < i - 1; m++)
	{
		cout << s[m];
		for(int n = 0; n < j - 2; n++)
		{
			cout << " ";
		
		}
		cout << s[len - m - 1] <<  endl;
	}
	for(int n = 0; n < j; n++)
	{
		cout << s[i - 1 + n];
	}
	return 0;
}
