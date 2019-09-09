#include <iostream>
#include <queue>
using namespace std;

struct mouse{
	int w, r;
}mm[1010];
int main()
{
	int n, k, t;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++) scanf("%d", &mm[i].w);
	queue<int> q;
	for(int i = 0; i < n; i++){
		scanf("%d", &t);
		q.push(t);
	}
	int temp = n, group;
	while(q.size() != 1){
		if(temp % k == 0) group = temp / k;
		else group = temp / k + 1;
		
		for(int i = 0; i < group; i++){
			int k1 = q.front();
			for(int j = 0; j < k; j++){
				if(i * k + j >= temp) break;
				int front = q.front();
				if(mm[front].w > mm[k1].w) k1 = front;
				mm[front].r = group + 1;
				q.pop();
			}
			q.push(k1);
		}
		temp = group;
	}
	mm[q.front()].r = 1;
	for(int i = 0; i < n; i++){
		printf("%d", mm[i].r);
		if(i < n - 1) printf(" ");
	}
	return 0;
} 
