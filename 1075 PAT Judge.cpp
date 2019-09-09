#include <iostream>
#include <set>
#include <cstring>
#include <algorithm>
using namespace std;

struct student{
	int id, score[6], sum, rank, pNum;
}stu[100010];
int ss[100010][6] = {0}, flag[100010][6] = {0}, total[100010] = {0}, perfect[100010] = {0};
int cmp(student s1, student s2){
	if(s1.sum != s2.sum) return s1.sum > s2.sum;
	return (s1.pNum != s2.pNum)? s1.pNum > s2.pNum : s1.id < s2.id; 	
}
int main()
{
	int n, k, m, score[5], t1, t2, t3, mm = 0;//mm为最大学号 
	cin >> n >> k >> m;
	set<int> dd;//存id
	memset(flag, -1, sizeof(flag));
	for(int i = 1; i <= k; i++) cin >> score[i];
	for(int i = 0; i < m; i++){
		cin >> t1 >> t2 >> t3;
		dd.insert(t1);
		mm = max(mm, t1);
		if(t3 != -1){
		if(t3 == score[t2] && t3 != ss[t1][t2]) perfect[t1]++;//防止重复提交 
		ss[t1][t2] = max (ss[t1][t2], t3);
		flag[t1][t2] = 1;
		}	
		else flag[t1][t2] = 0;
	}
	for(set<int>::iterator it = dd.begin(); it != dd.end(); it++){
		for(int i = 1; i <= k; i++){
			total[*it] += ss[*it][i];
		}
	}
	int r = 0;
	for(set<int>::iterator it = dd.begin(); it != dd.end(); it++){
		stu[r].id = *it;
		for(int i = 1; i <= k; i++) stu[r].score[i] = ss[*it][i];
		stu[r].sum = total[*it];
		stu[r].pNum = perfect[*it];
		r++;
	}
	sort(stu, stu + r, cmp);
	stu[0].rank = 1;
	for(int i = 1; i < r; i++){
		if(stu[i].sum != stu[i - 1].sum) stu[i].rank = i + 1;
		else stu[i].rank = stu[i - 1].rank;
	}
	for(int i = 0; i < r; i++){
		if((flag[stu[i].id][1] == -1|| flag[stu[i].id][1] == 0) && 
		(flag[stu[i].id][2] == -1|| flag[stu[i].id][2] == 0) &&
		(flag[stu[i].id][3] == -1|| flag[stu[i].id][3] == 0) &&
		(flag[stu[i].id][4] == -1|| flag[stu[i].id][4] == 0) &&
		(flag[stu[i].id][5] == -1|| flag[stu[i].id][5] == 0)) continue;
		printf("%d %05d %d",stu[i].rank, stu[i].id, stu[i].sum);
		for(int j = 1; j <= k; j++){
			if(flag[stu[i].id][j] == -1) cout << " -";
			else cout << " " << stu[i].score[j];
		}
		cout << endl;	
	}
	return 0;
 } 
