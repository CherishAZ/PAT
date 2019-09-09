#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int k)
{
	if(k <= 1) return false;
	if(k == 2) return true;
	int sqr = (int)sqrt(1.0 * k);
	for(int i = 2; i <= sqr; i++){
		if(k % i == 0) return false;
	}
	return true;
}
int flag[10010] = {0};
int main()
{
	int n, t, m;
	scanf("%d %d", &t, &n);
	while(!isPrime(t)) t++;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &m);
		int r1 = m % t, num = 1;
		while(flag[r1] && num < t) {
			r1 = (m + num * num) % t;//Æ½·½Ì½²â 
			num++;
		}
		if(num >= t) printf("-");
		else{
			flag[r1] = 1;
			printf("%d", r1);
		}
		if(i != n - 1) printf(" ");
	}
	return 0;
}
