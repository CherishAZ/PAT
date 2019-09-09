#include <iostream>
using namespace std;

int main()
{
	int a[3], b[3], c[3] = {0}, d[3] = {100000001, 17, 29};
	scanf("%d.%d.%d %d.%d.%d", &a[0], &a[1], &a[2], &b[0], &b[1], &b[2]);
	int temp = 0;
	
	for(int i = 2; i >= 0; i--)
	{
		c[i] = (a[i] + b[i] + temp) % d[i];
		temp = (a[i] + b[i] + temp) / d[i];
		cout << temp;
	}
	printf("%d.%d.%d", c[0], c[1], c[2]);
	return 0;
}
