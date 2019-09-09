#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
int main()
{
	ll n, t, sum1 = 0, sum2 = 0;
	vector<int> ss;
	scanf("%lld", &n);
	for(int i = 0; i < n; i++){
		scanf("%lld", &t);
		ss.emplace_back(t);
	}
	sort(ss.begin(), ss.end());
	if(n % 2 == 1) printf("1 ");	
	else printf("0 ");
	for(int i = 0; i < n; i++){
			sum1 += ss[i];
			if(i < n / 2) sum2 = sum1;
		}
	printf("%lld", sum1 - 2 * sum2);
	return 0;
}
