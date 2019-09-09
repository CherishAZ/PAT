#include <iostream>
#include <map>
using namespace std;

int main()
{
	int n, m, num = 0;
	string t, t1;
	cin >> n >> m;
	map<string, int> mm;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin >> t;
			mm[t]++;
			if(mm[t] > num){
				num = mm[t];
				t1 = t;
			}
		}
	}
 	cout << t1;
	return 0;
} 
