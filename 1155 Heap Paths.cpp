#include <iostream>
#include <vector>
using namespace std;
const int M = 1010;

int a[M], n;
vector<int> ss;
void dfs(int root){
	if(root * 2 > n && root * 2 + 1 > n){
		if(root <= n){
			for(int i = 0; i < ss.size(); i++){
				cout << ss[i];
				if(i != ss.size() - 1) cout << " ";
				else cout << endl;
			}
		}
	}else{
		ss.emplace_back(a[root * 2 + 1]);
		dfs(2 * root + 1);
		ss.pop_back();
		ss.emplace_back(a[root * 2]);
		dfs(2 * root);
		ss.pop_back();
	}
	
}
int main()
{
	int flag;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	flag = a[1] > a[2] ? 1 : -1;
	for(int i = 1; i <= n / 2; i++){
		int left = 2 * i, right = 2 * i + 1;
		if(flag == 1 && (a[left] > a[i] || (right <= n && a[right] > a[i]))) flag = 0;
		if(flag == -1 && (a[left] < a[i] || (right <= n && a[right] < a[i]))) flag = 0;
	}
	ss.emplace_back(a[1]);
	dfs(1);
	if(flag == 1) cout << "Max Heap" << endl;
	else if(flag == -1) cout << "Min Heap" << endl;
	else if(flag == 0) cout << "Not Heap" << endl;
	return 0;
}
