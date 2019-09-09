#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int k = 111;
const int INF = 1000000000;

struct customer{
	int comeTime, serveTime;
}newCustomer;
vector<customer> custom;
int convertTime(int h, int m, int s){
	return h * 3600 + m * 60 + s;
}
bool cmp(customer a, customer b){
	return a.comeTime < b.comeTime;
}
int endTime[k], totTime = 0;
int main()
{
	int stTime = convertTime(8, 0, 0);
	int edTime = convertTime(17, 0, 0);
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++) endTime[i] = stTime;
	for(int i = 0; i < n; i++){
		int h, m, s, serveTime;
		scanf("%d:%d:%d %d", &h, &m, &s, &serveTime);
		int comeTime = convertTime(h, m, s);
		if(comeTime > edTime) continue;
		newCustomer.comeTime = comeTime;
		newCustomer.serveTime = serveTime <= 60 ? serveTime * 60 : 3600;
		custom.push_back(newCustomer);
	}
	sort(custom.begin(), custom.end(), cmp);
	for(int i = 0; i < custom.size(); i++){
		int idx = -1, minEndTime = INF;
		for(int j = 0; j < m; j++){
			if(endTime[j] < minEndTime){
				minEndTime = endTime[j];
				idx = j;
			}
		}//每次循环找到最早空窗口 
		if(endTime[idx] <= custom[i].comeTime){
			endTime[idx] = custom[i].comeTime + custom[i].serveTime;
		}else{
			totTime += (endTime[idx] - custom[i].comeTime);
			endTime[idx] += custom[i].serveTime;
		}
	}
	if(custom.size() == 0) printf("0.0");
	else printf("%.1f", (totTime / 60.0 / custom.size()));
	return 0;
}
