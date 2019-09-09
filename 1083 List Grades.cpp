#include <iostream>
#include <algorithm>
using namespace std;

struct stu{
	string name, id;
	int score;
}ss[100010];
int cmp(stu s1, stu s2){
	return s1.score > s2.score;
}
int main()
{
	int n, sMin, sMax, flag = 0;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> ss[i].name >> ss[i].id >> ss[i].score;
	sort(ss, ss + n, cmp);
	cin >> sMin >> sMax;
	for(int i = 0; i < n; i++){
		if(ss[i].score >= sMin && ss[i].score <= sMax){
		cout << ss[i].name << " " << ss[i].id << endl;
		flag = 1;}
	}
	if(flag == 0) cout << "NONE";
	return 0;
}
