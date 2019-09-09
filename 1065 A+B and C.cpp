#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long long s;
	s = pow(-2, 64) ;
	printf("%llu",s); 
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		long double a, b, c;
		cin >> a >> b >> c;
		cout << "Case #" << i << ": " ;
		if( a + b > c)
		cout << "true" << endl;
		else
		cout << "false" << endl;
	}
	
	return 0;
 } 
