#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int a[10010], mm[10010][10010];
int cmp(int a, int b){
	return b > a;
}
int main()
{
	int N, num = 0;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> a[i];
	}
	if( N == 1){
		cout << a[0];
		return 0;
	}
	int m = (int)ceil(sqrt(1.0 * N));
	while( N % m != 0) m++; 
	sort(a, a + N, cmp);
	int i = 1, j = 1, n = N / m;
	int U = 1, D = m, L = 1, R = n;
	while( num < N ){
		while(num < N && j < R){
			mm[i][j] = a[num++];
			j++;
		}
		while(num < N && i < D){
			mm[i][j] = a[num++];
			i++;
		}
		while(num < N && j > L){
			mm[i][j] = a[num++];
			j--;
		}
		while(num < N && i > U){
			mm[i][j] = a[num++];
			i--;
		}
		U++,D--,L++,R--;
		i++, j++;
		if(num == N - 1) mm[i][j] = a[num++];
	}
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			cout << mm[i][j];
			if(j < n) cout << " ";
			else cout << endl;
		}
	}
	return 0;
 } 
