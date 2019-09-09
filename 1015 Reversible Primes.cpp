#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

bool isPrime(int k)
{
	if(k <= 1) return false;//���� 
	int sqr = (int)sqrt(1.0 * k);
	for(int i = 2; i <= sqr; i++){
		if(k % i == 0) return false;
	}
	return true;
}
int k1[110];
int main()
{
	int n, d;
	while(scanf("%d", &n) != EOF)
	{
		int num = 0, k = 0, k_r = 0;
		if(n < 0) break;
		scanf("%d", &d);
		if(!isPrime(n)) printf("No\n");
		else{
			while(n){
				k1[num++] = n % d;
				n /= d;
			}//����ת�� 
			for(int i = 0; i < num; i++){
				k_r = k_r  * d + k1[i];
			}//ת��Ϊ10���� 
			if(isPrime(k_r)) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
} 
