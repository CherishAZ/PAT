#include <iostream>
using namespace std;
int flag[100010] = {0};
int main()
{
	int n, t;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &t);
		if(t > 0 && t < 100010) flag[t] = 1;
	}
	for(int i = 1; i < 100010; i++){
		if(flag[i] == 0){
			printf("%d\n", i);
			break;
		} 
	}
	return 0;
}
