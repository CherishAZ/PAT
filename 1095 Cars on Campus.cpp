#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

struct car{
	string pn;
	int status, time;
}cc[10010];
int cmp(car c1, car c2){
	return c1.pn != c2.pn ? c1.pn < c2.pn : c1.time < c2.time;
}
int cmp1(car c1, car c2){
	return c1.time < c2.time;
}
int main()
{
	int n, k, r = 0, largest = 0, count = 0;
	cin >> n >> k;
	vector<car> kk;
	map<string, int> total;//停车总时长 
	for(int i = 0; i < n; i++){
		string temp;
		int t1, t2, t3;
		cin >> cc[i].pn;
		scanf("%d:%d:%d", &t1, &t2, &t3);
		cin >> temp;
		if(temp == "in") cc[i].status = 1;
		else cc[i].status = 0;
		cc[i].time = t1 * 3600 + t2 * 60 + t3;
	}
	sort(cc, cc + n, cmp);
	for(int i = 1; i < n; i++){
		if(cc[i].pn == cc[i - 1].pn && cc[i - 1].status == 1 && cc[i].status == 0){
			kk.push_back(cc[i - 1]);
			kk.push_back(cc[i]);
			total[cc[i].pn] += cc[i].time - cc[i - 1].time;
			largest = max(largest, total[cc[i].pn]);
		}
	}
	sort(kk.begin(), kk.end(), cmp1);
	for(int i = 0; i < k; i++){
		int t, t1, t2, t3, num = 0;
		scanf("%d:%d:%d", &t1, &t2, &t3);
		t = t1 * 3600 + t2 * 60 + t3;
		while(r < kk.size() && kk[r].time <= t){
			if(kk[r].status == 1) count++;
			else count--;
			r++;
		}
		cout << count << endl;
	}
	for(map<string, int> :: iterator it = total.begin(); it != total.end(); it++)
		if(it -> second == largest) cout << it -> first << " ";
	printf("%02d:%02d:%02d", largest / 3600, largest % 3600 / 60, largest % 3600 % 60);
	return 0;
} 
