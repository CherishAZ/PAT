#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
using namespace std;

int quota[110] = {0}, flag[110];
struct student{
	int ge, gi, gs, rank, choice[6], start;
}ss[40010];
int cmp(student s1, student s2){
	return s1.gs != s2.gs? s1.gs > s2.gs : (s1.ge != s2.ge ? s1.ge > s2.ge : s1.start < s2.start);
}
int main()
{
	memset(flag, -1, sizeof(flag));
	int n, m, k, r = 0;
	cin >> n >> m >> k;
	map<int, vector<int> > mm;
	for(int i = 0; i < m; i++) cin >> quota[i];
	for(int i = 0; i < n; i++){
		ss[i].start = i;
		cin >> ss[i].ge >> ss[i].gi;
		ss[i].gs = (ss[i].ge + ss[i].gi);
		for(int j = 0; j < k; j++)	cin >> ss[i].choice[j];
	}
	sort(ss, ss + n, cmp);
	ss[0].rank = 1;
	for(int i = 1; i < n; i++){
		if(ss[i].gs == ss[i - 1].gs && ss[i].ge == ss[i - 1].ge) ss[i].rank = ss[i - 1].rank;
		else ss[i].rank = i + 1;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < k; j++){
			int ch = ss[i].choice[j];
			if(quota[ch] > 0 || (flag[ch] != -1 && ss[flag[ch]].rank == ss[i].rank)){
				mm[ch].push_back(ss[i].start);
				quota[ch]--;
				flag[ch] = i;
				break;
			}
		}
	}
	for(int i = 0; i < m; i++){
		if(mm[i].size() != 0){
			sort(mm[i].begin(), mm[i].end());
			for(int j = 0; j < mm[i].size(); j++){
				if(j != 0) cout << " ";
				cout << mm[i][j];
			}
		}
		cout << endl;
	}
//	if(mm.size() == 0){
//		for(int i = 0; i < m; i++) cout << endl;
//		return 0;
//	}
//	for(map<int, vector<int> > :: iterator it = mm.begin(); it != mm.end(); it++){
//		while(r++ != it -> first) cout << endl;
//		vector<int> temp = it -> second;
//		sort(temp.begin(), temp.end());
//		for(int i = 0; i < temp.size(); i++){
//			cout << temp[i];	
//			if(i < temp.size() - 1) cout << " ";
//		}
//		cout << endl;
//	}
	return 0;
}
