#include <iostream>
using namespace std;

int main()
{
	int n£¬ i = 0;
	cin >> n;
	double sum = 0.0;
	double x;
	while(cin >> x)
	{
		sum += x * (n - i) * ( i + 1) ; 
		++i;
		if( cin.get() == '\n')
		break;	
	}
	printf("%.2f", sum);
	return 0;
}
