#include <iostream>
#include <algorithm>
using namespace std;

int number[1010], cbt[1010], index = 0, n;
void inorder(int root){
	if(root > n) return;
	inorder(root * 2);
	cbt[root] = number[index++];
	inorder(root * 2 + 1);
}
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &number[i]);
	sort(number, number + n);
	inorder(1);
	for(int i = 1; i <= n; i++){
		printf("%d", cbt[i]);
		if(i != n) printf(" ");
	}
	return 0;
}
