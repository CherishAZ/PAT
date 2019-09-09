#include <iostream>
using namespace std;
const int M = 1010;

int a[M], m, n;
void postOrder(int root){
	if(root > n) return;
	postOrder(2 * root);
	postOrder(2 * root + 1);
	cout << a[root];
	if(root != 1) cout << " ";
}
int main()
{
	cin >> m >> n;
	for(int i = 0; i < m; i++){
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		int flag = a[1] > a[2] ? 1 : -1;
		for(int j = 1; j <= n / 2; j++){
			int left = 2 * j, right = 2 * j + 1;
			if(flag == 1 && (a[left] > a[j] || ( right <= n && a[right] > a[j]))) flag = 0;
			if(flag == -1 && (a[left] < a[j] || ( right <= n && a[right] < a[j]))) flag = 0;
		}
		if(flag == 0) cout << "Not Heap" << endl;
		else if(flag == 1) cout << "Max Heap" << endl;
		else if(flag == -1) cout << "Min Heap" << endl;
		postOrder(1);
		cout << endl;
	}
	return 0;
}
