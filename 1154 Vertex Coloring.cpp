#include <iostream>
#include <set>
using namespace std;
const int M = 10010;

struct edge{
	int a, b;
}ee[M];
int color[M];
int main()
{
	int n, m, k;
	cin >> n >> m;
	set<int> ss;
	for(int i = 0; i < m; i++) cin >> ee[i].a >> ee[i].b;
	cin >> k;
	while(k--){
		int flag = 1;
		if(!ss.empty()) ss.clear();
		for(int i = 0; i < n; i++){
			cin >> color[i];
			ss.insert(color[i]);
		}
		for(int i = 0; i < m; i++){
			if(color[ee[i].a] == color[ee[i].b]){
				flag = 0;
				break;
			}
		}
		if(flag == 0) cout << "No" << endl;
		else cout << ss.size() << "-coloring" << endl;
	}
	return 0;
} 
