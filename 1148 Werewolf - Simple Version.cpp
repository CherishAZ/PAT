#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const int M = 110;

int ss[M], a[M];
int main()
{
	int n, t, sum = 0, flag = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> ss[i];
		sum += t;
	}
	for(int i = 1; i < n; i++){
		for(int j = i + 1; j <= n; j++){
			fill(a, a + M, 1);
			vector<int> lie;
			a[i] = a[j] = -1;//wolf
			for(int l = 1; l <= n; l++){
				if(a[abs(ss[l])] * ss[l] < 0)
				lie.emplace_back(l);
			}
			if(lie.size() == 2 && a[lie[0]] + a[lie[1]] == 0){
				cout << i << " " << j;
				flag = 1;
				break;
			}	
		}
		if(flag) break;
	}
	if(!flag) cout << "No Solution" << endl;
	return 0;
}
