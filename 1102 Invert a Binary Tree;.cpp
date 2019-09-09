#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int num = 0, n;
vector<int> s1;
struct node{
	int lchild = -1, rchild = -1;
}nn[110];
int notRoot[110] = {0};//记录根节点 
void LayerOrder(int r){
	queue<int> q;
	q.push(r);
	while(!q.empty()){
		int front = q.front();
		q.pop();
		printf("%d", front);
		if(++num < n) printf(" ");
		if(nn[front].rchild != -1) q.push(nn[front].rchild);
		if(nn[front].lchild != -1) q.push(nn[front].lchild);
	}
}
void r_inOrder(int r){
	if(r == -1) return;
	r_inOrder(nn[r].lchild);
	s1.push_back(r);
	r_inOrder(nn[r].rchild);
}
int main()
{
	int r;
	scanf("%d", &n);
	getchar();
	string s;
	for(int i = 0; i < n; i++){
		getline(cin, s);
		if(s[0] == '-') nn[i].lchild == -1;
		else{
			nn[i].lchild = s[0] - '0';
			notRoot[nn[i].lchild] = 1;
		} 
		if(s[2] == '-') nn[i].rchild = -1;
		else{
			nn[i].rchild = s[2] - '0';
			notRoot[nn[i].rchild] = 1;
		}
	}
	for(r = 0; r < n; r++)
	if(!notRoot[r]) break;
	LayerOrder(r);
	printf("\n");
	r_inOrder(r);
	for(int i = s1.size() - 1; i > 0; i-- ) printf("%d ", s1[i]);
	printf("%d", *s1.begin());
	return 0;
} 
