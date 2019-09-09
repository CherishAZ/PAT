#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int M = 10010;

queue<int> qv;
struct customer{
	int comeTime, serveTime, leaveTime;
	int tag, rank = -1;
}cc;
vector<customer> ss;
struct table{
	int id, tag;
	int endTime, num;
}tt[110];
int convertTime(int h, int m, int s){
	return h * 3600 + m * 60 + s;
}
int cmp(customer c1, customer c2){
	return c1.comeTime < c2.comeTime;
}
int cmp1(customer c1, customer c2){
	return (c1.leaveTime - c1.serveTime) != (c2.leaveTime - c2.serveTime) ? (c1.leaveTime - c1.serveTime) < (c2.leaveTime - c2.serveTime) : c1.rank < c2.rank;
}
void showTime(int a, int b, double c){
	if(b >= convertTime(21, 0 , 0)) return;
	int t1 = a / 3600, t2 = a % 3600 / 60, t3 = a % 60;
	int t11 = b / 3600, t22 = b % 3600 / 60, t33 = b % 60;
	double t111 = round(c / 60.0);
	printf("%02d:%02d:%02d %02d:%02d:%02d %.0f\n", t1, t2, t3, t11, t22, t33, t111);
}
int main()
{
	int n, k, tag, h, m, s, serveTime, temp, stTime = convertTime(8, 0, 0), edTime = convertTime(21, 0, 0);
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d:%d:%d %d %d", &h, &m, &s, &serveTime, &tag);
		cc.comeTime = convertTime(h, m, s);
		if(cc.comeTime >= edTime) continue;
		cc.serveTime = (serveTime <= 120 ? serveTime * 60 : 7200);
		cc.tag = tag;
		ss.push_back(cc);
	}
	scanf("%d%d", &k, &m);
	for(int i = 0; i < k; i++){
		tt[i].id = i;
		tt[i].tag = tt[i].num = 0;
		tt[i].endTime = stTime;
	}
	for(int i = 0; i < m; i++){
		scanf("%d", &temp);
		tt[temp - 1].tag = 1;
	}
	sort(ss.begin(), ss.end(), cmp);
	int index = 0, top, pos = 0;
	for(int temp_index = 0; temp_index < n; temp_index++){
		if(ss[temp_index].tag == 1) qv.push(temp_index);
	}
	int flag2 = 0;
	for(; index < ss.size(); index++){
		int minTime = 1 << 30, idx = -1, idx1 = -1, flag = 1, flag1 = 1,maxTime = 1 << 30;
		for(int i = 0; i < k; i++){
			if(tt[i].endTime != stTime) maxTime = min(maxTime, tt[i].endTime);
		}
		if(flag2){
			for(int i = 0; i < k; i++){
				if(tt[i].endTime == stTime){
					tt[i].endTime = maxTime;
				}
			}
		}
		for(int i = 0; i < k; i++){
			if(tt[i].endTime < minTime){
				minTime = tt[i].endTime;
				idx = i;
				flag = 1;
			}else if(tt[i].endTime == minTime && tt[i].tag == 1 && flag){
				idx1 = i;
				flag = 0;
			}
		}
		flag2 = 1;
		if(idx1 == -1) idx1 = idx;
		if(tt[idx].endTime >= edTime || tt[idx1].endTime >= edTime) break;
		if(!qv.empty()) top =  qv.front();
		if((tt[idx1].tag == 1 && !qv.empty() && ss[top].comeTime <= tt[idx1].endTime && ss[top].rank == -1) ||(tt[idx1].tag == 1 && !qv.empty() && ss[top].comeTime <= tt[idx1].endTime && ss[top].rank == -1 && top < k)){
			tt[idx1].num++;
			qv.pop();
			tt[idx1].endTime += ss[top].serveTime;	
			ss[top].rank = index;
			ss[top].leaveTime = tt[idx1].endTime;
		}else{
			tt[idx].num++;
			int temp1 = 0;
			while(ss[temp1].rank != -1 && temp1 < ss.size()) temp1++;
			if(temp1 == ss.size()) break;
			if(ss[temp1].tag == 1) qv.pop();
			if(ss[temp1].comeTime <= tt[idx].endTime) tt[idx].endTime += ss[temp1].serveTime;
			else tt[idx].endTime = ss[temp1].comeTime + ss[temp1].serveTime;
			ss[temp1].rank = index;
			ss[temp1].leaveTime = tt[idx].endTime;
		}				
	}
	sort(ss.begin(), ss.end(), cmp1);
	for(int i = 0; i < ss.size(); i++){
		if(ss[i].rank < 0) continue;
		double waitTime = ss[i].leaveTime - ss[i].serveTime - ss[i].comeTime;
		int serveTime = ss[i].leaveTime - ss[i].serveTime;
		showTime(ss[i].comeTime, serveTime, waitTime);
	}
	for(int i = 0; i < k - 1; i++) printf("%d ", tt[i].num);
	printf("%d", tt[k - 1].num);
	return 0;
} 
