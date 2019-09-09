#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int M = 1111;

int n, m, query, k, q;
struct Window{
	int endTime, popTime;
	queue<int> q;
}window[20];
int ans[M], needTime[M];
int main()
{
	int inIndex= 0;
	scanf("%d%d%d%d", &n, &m, &k, &query);
	for(int i = 0; i < k; i++) scanf("%d", &needTime[i]);
	for(int i = 0; i < n; i++) window[i].popTime = window[i].endTime = 8 * 60;
	for(int i = 0; i < min(m * n, k); i++){
		window[inIndex % n].q.push(inIndex);
		window[inIndex % n].endTime += needTime[inIndex];
		if(inIndex < n) window[inIndex].popTime = needTime[inIndex];
		ans[inIndex] = window[inIndex % n].endTime;
		inIndex++;
	}
	for(; inIndex < k; inIndex++){
		int idx = -1, minPopTime = 1 << 30;
		for(int i = 0; i < n; i++){
			if(window[i].popTime < minPopTime){
				idx = i;
				minPopTime = window[i].popTime;
			}
		}
		Window& W = window[idx];
		W.q.pop();
		W.q.push(inIndex);
		W.endTime += needTime[inIndex];
		W.popTime += needTime[W.q.front()];
		ans[inIndex] = W.endTime;
	}
	for(int i = 0; i < query; i++){
		scanf("%d", &q);
		if(ans[q - 1] - needTime[q - 1] >= 17 * 60) printf("Sorry\n");
		else printf("%02d:%02d\n", ans[q - 1] / 60, ans[q - 1] % 60);
	}
	return 0;
} 
