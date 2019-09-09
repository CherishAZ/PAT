#include <iostream>
using namespace std;

int main()
{
	int up = 6, down = 4, stay = 5;
	int n, sum = 0;
	cin >> n;
	int a1, a2 = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> a1;
		if( a1 > a2)
		{
			sum += (up * (a1 - a2));
		}
		if( a1 < a2)
		{
			sum += (down * (a2 - a1)); 
		}
		a2 = a1;
	}
	sum += stay * n;
	cout << sum;
	return 0;
}
