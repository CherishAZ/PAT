#include <iostream>
using namespace std;

int ss[100010], rr[100010];
int main()
{
	int n, t;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &rr[i]);
		ss[rr[i]]++;
	}
	for(int i = 0; i < n;i++){
		if(ss[rr[i]] == 1){
			printf("%d", rr[i]);
			return 0;
		}
	}
	printf("None");
	return 0;
}
