#include <iostream>
#include <set>
using namespace std;

set<int> ss[51];
int main()
{
	int n, t, t1, k;
	double r;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> t;
		for(int j = 0; j < t; j++){
			cin >> t1;
			ss[i].insert(t1);
		}
	}
	cin >> k;
	for(int i = 0; i < k; i++){
		int num = 0, num1 = 0;
		cin >> t >> t1;
		for(set<int>::iterator it = ss[t].begin(); it != ss[t].end(); it++){
			if(ss[t1].find(*it) != ss[t1].end()) num++;
			else num1++;
		}
//		r = (double)num / (double)(num1 + ss[t1].size());
//		printf("%.1lf%\n",r*100.0);
		printf("%.1lf%\n",num * 100.0 / (num1 + ss[t1].size()));
	}
	return 0;
}
/*
3
3 99 87 101
4 87 101 5 87
7 99 101 18 5 135 18 99
2
1 2
1 3
*/
