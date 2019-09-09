#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[100100];
int main()
{
	int n, num = 0, t, pos, sum, k = 1; 
	scanf("%d", &n);
	sum = n - 1;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		if(a[i] == i && i != 0) sum--;
	}
	while(sum > 0){
		if(a[0] == 0){
			while(k < n){
				if(a[k] != k){
					swap(a[0], a[k]);
					num++;
					break; 
				}
				k++;
			} 
		}
		while(a[0] != 0){
			swap(a[0], a[a[0]]);
			num++;
			sum--;
		}
	}
	printf("%d", num);
	return 0;
}
