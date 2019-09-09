#include <iostream>
#include <cmath>
using namespace std;

int a[1010];
int main()
{
	int n, m;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &m);
		int flag = 1;
		for(int j = 1; j <= m; j++) scanf("%d", &a[j]);
		for(int l = 1; l <= m; l++){
			for(int k = l + 1; k <= m; k++){
				if( a[k] == a[l] || (k - l == abs(a[k] - a[l]))){
					flag = 0;
					break;
				}
			}
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
} 
