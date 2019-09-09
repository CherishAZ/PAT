#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct node{
	int val;
	int lchild, rchild;
}nn[110];
int n, a[110], index = 0, num = 0;
void insert(int root){
	if(index > n || root == -1) return ;
	insert(nn[root].lchild);
	nn[root].val = a[index++];
	insert(nn[root].rchild);
}
void levelOrder(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int top = q.front();
		q.pop();
		printf("%d", nn[top].val);
		if(++num < n) printf(" ");
		if(nn[top].lchild != -1) q.push(nn[top].lchild);
		if(nn[top].rchild != -1) q.push(nn[top].rchild);
	}
}
int main()
{
	int t1, t2;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d%d", &nn[i].lchild, &nn[i].rchild);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n);
	insert(0);
	levelOrder(0);
	return 0;
}
