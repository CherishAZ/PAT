#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int M = 1010;

int n, l;
struct node{
	int layer;
	int id;
};
vector<node> G[M];
bool inq[M] = {false};
int bfs(int s, int l){
	int num = 0;
	queue<node> q;
	node start;
	start.id = s;
	start.layer = 0;
	q.push(start);
	inq[start.id] = true;
	while(!q.empty()){
		node top = q.front();
		q.pop();
		int u = top.id;
		for(int i = 0; i < G[u].size(); i++){
			node next = G[u][i];
			next.layer = top.layer + 1;
			if(!inq[next.id] && next.layer <= l){
				num++;
				q.push(next);
				inq[next.id] = true;
			}
		}
	}
	return num;
}
int main()
{
	node user;
	int t1, t2, t3;
	scanf("%d%d", &n, &l);
	for(int i = 1; i <= n; i++){
		user.id = i;
		scanf("%d", &t1);
		for(int j = 0;  j < t1; j++){
			scanf("%d", &t2);
			G[t2].emplace_back(user);
		}
	}
	int numQuery, s;
	scanf("%d", &numQuery);
	for(int i = 0; i < numQuery; i++){
		memset(inq, false, sizeof(inq));
		scanf("%d", &t3);
		int num = bfs(t3, l);
		printf("%d\n", num);
	}
	return 0;
}
