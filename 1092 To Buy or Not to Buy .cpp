#include <iostream>
#include <cmath> 
using namespace std;

int main()
{
	string s, n;
	getline (cin, s);
	getline (cin, n);
	int count[256] = {0};
	for( int i = 0; i < s.length(); ++i)
	count[s[i]]++;
	for( int i = 0; i < n.length(); ++i)
	count[n[i]]--;	
	int sum = 0, sum1 = 0;
	for( int i = 0; i < 256; ++i)
	{
		if(count[i] < 0) sum1 += count[i];
		else sum += count[i];
	}	
	if(sum1 != 0) cout << "No" << " " << abs(sum1);
	else cout << "Yes" << " "<< sum;
	return 0;
}
