#include <iostream>
#include <queue>
using namespace std;

struct node{
	int v, h = 1;
	node *lchild, *rchild;
};
int num[1010] = {0}, maxL = 1;//数组大小 
node* newNode(int v){
	node* Node = new node;
	Node->v = v;
	Node->lchild = Node->rchild = NULL;
	return Node;
}
void insert(node* &root, int v){
	if(root == NULL){
		root = newNode(v);//不要new node，修改的是参数里的root 
		return;
	}
	else if(v <= root->v) insert(root->lchild, v); 
	else insert(root->rchild, v);
}
void layerTraverse(node* root){
	queue<node*> q;
	q.push(root);
	root->h = 1;
	while(!q.empty()){
		node* temp = q.front();
		num[temp->h]++;
		if(temp->h > maxL) maxL = temp->h;
		q.pop();
		if(temp->lchild != NULL){
			q.push(temp->lchild);
			temp->lchild->h = temp->h + 1;
		}
		if(temp->rchild != NULL){
			q.push(temp->rchild);
			temp->rchild->h = temp->h + 1;
		}
	}
}
//void dfs(node* root, int depth){
//	if(root == NULL){
//		maxL = max(depth, maxL);
//		return;
//	}
//	num[depth]++;
//	dfs(root->lchild, depth+1);
//	dfs(root->rchild, depth+1);
//}
int main()
{
	int n, t;
	cin >> n;
	node* root = NULL;
	for(int i = 0; i < n; i++){
		cin >> t;
		insert(root, t);
	}
	layerTraverse(root);
	int v1 = num[maxL], v2 = num[maxL - 1];
	cout << v1 << " + " << v2 << " = " << v1 + v2;
	return 0;
}
