#include <iostream>
#include <vector>
using namespace std;

int main()
{
	double w[3], t[3], l[3], max[3];
	int m[3];
	char p[3] = {'W', 'T', 'L'};
	for(int i = 0 ; i < 3; i++)
	{
		cin >> w[i] >> t[i] >> l[i];
		max[i] = w[i] > (t[i] > l[i] ? t[i] : l[i]) ? w[i] :(t[i] > l[i] ? t[i] : l[i]);
		if(max[i] == w[i])
		m[i] = 0;
		if(max[i] == t[i])
		m[i] = 1;
		if(max[i] == l[i])
		m[i] = 2;
	}
	double sum = 2 * (max[0] * max[1] * max[2] * 0.65 - 1);
	for(int i = 0; i < 3; i++)
	{
		cout << p[m[i]] << " ";
	}
	printf("%.2lf", sum);
	return 0;
}
