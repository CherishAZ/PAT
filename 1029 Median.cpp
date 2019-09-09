#include <iostream>
using namespace std;
const int M = 200050;
const int INF = 1<<31 -1 ;
int s1[M];
int main()
{
	int n, m, p, t, count = -1;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &s1[i]);
	s1[n] = INF;
	
	int j = 0;
	scanf("%d", &m);
	p = (n + m - 1) / 2;
	for(int i = 0; i < m; i++){
		scanf("%d", &t);
		while(s1[j] < t){
			count++;
			if(count == p) printf("%d", s1[j]);
			j++;
		}
		count++;
		if(count == p) printf("%d", t);
	}
	while(j < n){
		count++;
		if(count == p) printf("%d", s1[j]);
		j++;
	}
	return 0;
} 

