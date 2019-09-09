#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const int M = 100100;

int Hash[M];
bool isPrime(int x){
	int sqr = (int)sqrt(1.0 * x);
	for(int i = 2; i <= sqr; i++){
		if(x % i == 0) return false;
	}
	return true;
}
int main()
{
	memset(Hash, -1, sizeof(Hash));
	int msize, n, m, t, num = 0, pos;
	cin >> msize >> n >> m;
	while(!isPrime(msize)) msize++;
	for(int i = 0; i < n; i++){
		cin >> t;
		int flag = 0;
		for(int j = 0; j < msize; j++){//create <msize || <= msize
			pos = (t + j * j) % msize; //quadratic probing (quadratic is in parenthese)
			if(Hash[pos] == -1){
				Hash[pos] = t;
				flag = 1;
				break;
			}
		}
		if(!flag) cout << t << " cannot be inserted." << endl;
	}
	int sum = 0;
	for(int i = 0; i < m; i++){
		cin >> t;
		for(int j = 0; j <= msize; j++){//<=msize
			sum++;
			pos = (t + j * j) % msize;
			if(Hash[pos] == t || Hash[pos] == -1) break;
		}
		cout << sum << endl;
	}
	printf("%.1lf\n", sum * 1.0 / m);
	return 0;
		
}
