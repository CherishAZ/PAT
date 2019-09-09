/* Time Exceeded
#include <iostream>
#include <set>
#include <map> 
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

unordered_map<int, set<string> > ss;
int main()
{
	int n, k, t1, t2;
	scanf("%d %d", &n, &k);
	string t;
	vector<int> s;
	for(int i = 0; i < k; i++){
		scanf("%d %d", &t1, &t2);
		for(int j = 0; j < t2; j++){
			cin >> t;
			ss[t1].insert(t);
		}
	}
	for(int i = 0; i < n; i++){
		cin >> t;
		for(int j = 1; j <= k; j++){
			set<string> ::iterator it = ss[j].find(t);
			if(it != ss[j].end()) s.push_back(j);
		}
		printf("%s %d", t.c_str(), s.size());
		for(int ii = 0; ii < s.size(); ii++) printf(" %d", s[ii]);
		printf("\n");
		s.clear();
	}
	return 0;
}
*/
//转换到hash数组，但又不能用二维数组，否则内存超限，用vector能减少内存开销。 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 40010;
const int M = 26*26*26*10+1;
vector<int> stu[M];
int getId(string s)
{
	int id = 0;
	for(int i = 0; i < 3; i++)	id = id * 26 + (s[i] - 'A');
	id = id * 10 + s[3] - '0';
	return id;
}
int main()
{
	int n, k, t1, t2;
	char name[5];
	scanf("%d %d", &n, &k);
	for(int i = 0; i < k; i++){
		scanf("%d %d", &t1, &t2);
		for(int j = 0; j < t2; j++){
			scanf("%s", name);
			int id = getId(name);
			stu[id].push_back(t1);
		}
	}
	for(int i = 0; i < n; i++){
		scanf("%s", name);
		int id = getId(name);
		sort(stu[id].begin(), stu[id].end());
		printf("%s %d", name, stu[id].size());
		for(int ii = 0; ii < stu[id].size(); ii++) printf(" %d", stu[id][ii]);
		printf("\n");
	}
}

