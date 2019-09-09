#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, origin[110], step1[110], copy1[110], copy2[110];

bool isSame(int A[], int B[]){
	for(int i = 1; i <= n; i++) if(A[i] != B[i]) return false;
	return true;
}
void showArray(int A[]){
	for(int i = 1; i <= n; i++){
		cout << A[i];
		if( i < n) cout << " ";
	}
}
bool insertion(){
	bool flag = false;
	for(int i = 2; i < n; i++){
		if(i != 2 && isSame(copy1, step1)) flag = true;
		sort(copy1, copy1 + i + 1);
		if(flag == true) return true;
	}
	return false;
}
void downAdjust(int low, int high){
	int i = low, j = 2 * i;
	while( j <= high){
		if(high >= j + 1 && copy2[j + 1] > copy2[j])
		j = j + 1;
		if(copy2[j] > copy2[i]){
			swap(copy2[j], copy2[i]);
			i = j;
			j = 2 * i;
		}
		else break;
	}
}
void heapsort(){
	bool flag = false;
	for(int i = n / 2; i >= 1; i--) downAdjust(i, n);
	for(int i = n; i > 1; i--){
		if( i != n && isSame(copy2, step1)) flag = true;
		swap(copy2[i], copy2[1]);
		downAdjust(1, i - 1);
		if(flag == true){
			showArray(copy2);
			return;
		}
	}
}
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> origin[i];
		copy1[i] = origin[i];
		copy2[i] = origin[i];
	}
	for(int i = 1; i <= n; i++) cin >> step1[i];
	if(insertion()){
		cout << "Insertion Sort" << endl;
		showArray(copy1);
	}else{
		cout << "Heap Sort" << endl;
		heapsort();
	}
	return 0;
}
