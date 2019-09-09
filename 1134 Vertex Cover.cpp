#include <iostream>
#include <cstring>
using namespace std;
const int M = 10010;

int E[M] = {0};
struct edge{
	int a, b;
}ee[M];
int main()
{
	int n, m, t1, t2, k, k1, t, flag;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> ee[i].a >> ee[i].b;
	}
	cin >> k;
	for(int j = 0; j < k; j++){
		cin >> k1;
		memset(E, 0, sizeof(E));
		flag = 1;
		for(int i = 0; i < k1; i++){
			cin >> t;
			E[t] = 1;
		}
		for(int i = 0; i < m; i++){
			if(E[ee[i].a] == 0 && E[ee[i].b] == 0){
				flag = 0;
				break;
			}
		}
		if(flag) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
