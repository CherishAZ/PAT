#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;
int main()
{
	int n;
	cin >> n;
	ll sqr = (ll)sqrt(1.0 * n), ansI = 0, ansLen = 0;
	for(ll i = 2; i <= sqr; i++){
		ll temp = 1, j = i;
		while(1){
			temp *= j;
			if(n % temp != 0) break;
			if(j - i + 1 > ansLen){
				ansI = i;
				ansLen = j - i + 1;
			}
			j++;
		}
	}
	if(ansLen == 0) cout << 1 << endl << n << endl;
	else{
		cout << ansLen << endl;
		for(ll i = 0; i < ansLen; i++){
			cout << ansI + i;
			if( i != ansLen - 1) cout << "*";
		}
	}
	return 0;
} 
