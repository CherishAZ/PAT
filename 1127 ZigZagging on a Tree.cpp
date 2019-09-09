#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int M = 110;

int n, post[M], in[M], layer[M], max_h = 0;
vector<int> ss[M];
struct node{
	node *lchild, *rchild;
	int v, h;
};
node* create(int postl, int postr, int inl, int inr){
	if(postl > postr) return NULL;
	node* root = new node;
	root->v = post[postr];
	int k;
	for(k = inl; k <= inr; k++){
		if(in[k] == post[postr]) break;
	}
	int numleft = k - inl;
	root->lchild = create(postl, postl + numleft - 1, inl, k - 1);
	root->rchild = create(postl + numleft, postr - 1, k + 1, inr);
	return root; 
} 
void layerTraverse(node* root){
	queue<node*> q;
	q.push(root);
	root->h = 1;
	while(!q.empty()){
		node* top = q.front();
		ss[top->h].emplace_back(top->v);
		max_h = max(max_h, top->h);
		q.pop();
		if(top->lchild != NULL){
			q.push(top->lchild);
			top->lchild->h = top->h + 1;	
		}
		if(top->rchild != NULL){
			q.push(top->rchild);
			top->rchild->h = top->h + 1;	
		}
	}
}
int main()
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> in[i];
	for(int i = 0; i < n; i++) cin >> post[i];
	node* root = create(0, n - 1, 0, n - 1);
	layerTraverse(root);
	for(int i = 1; i <= max_h; i++){
		if(i % 2 == 1) reverse(ss[i].begin(), ss[i].end());
		for(int j = 0; j < ss[i].size(); j++){
			cout << ss[i][j];
			if(i == max_h && j == ss[i].size() - 1) continue;
			else cout << " ";
		}
	}
	return 0;
} 
