#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int M = 10010;

bool flag[M] = {false};
int isPrime(int x){
	int sqr = (int)sqrt(1.0 * x);
	int i;
	for(i = 2; i <= sqr; i++){
		if(x % i == 0){
			return false;
		}
	}
	return true;
}
int main()
{
	int n, m, t;
	scanf("%d", &n);
	map<int ,int> mm;
	for(int i = 1; i <= n; i++){
		scanf("%d", &t);
		mm[t] = i;
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d", &t);
		if(mm.find(t) != mm.end()){
				if(!flag[t]){
					if(mm[t] == 1){
						printf("%04d: Mystery Award\n", t);
						flag[t] =true;
					}else if(isPrime(mm[t])){
						printf("%04d: Minion\n", t);
						flag[t] = true;
					}else{
					printf("%04d: Chocolate\n", t);
					flag[t] = true;
				}	
			}else{
				printf("%04d: Checked\n", t);
			}
		}else printf("%04d: Are you kidding?\n", t);
	}
	return 0;
}
