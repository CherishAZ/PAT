#include <iostream>
#include <algorithm>
using namespace std;

int num[10010], flag[10010];
int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	for(int i = 0; i < m; i++){
		scanf("%d", &num[i]);
		flag[num[i]]++;
	}
	sort(num, num + m);
	for(int i = 0; i < m; i++){
		if((flag[num[i]] != 0 && flag[n - num[i]] != 0 && n != 2 * num[i]) || (n == 2 * num[i] && flag[num[i]] >= 2)){
			printf("%d %d", num[i], n - num[i]);
			return 0;
		}
	}
	printf("No Solution");
	return 0;
}

