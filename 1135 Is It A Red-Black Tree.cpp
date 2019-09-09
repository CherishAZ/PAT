#include <iostream>
#include <cmath>
using namespace std;

int m, n; 
struct node{
	node *lchild, *rchild;
	int v;
};
node* newNode(int v){
	node* Node = new node;
	Node->v = v;
	Node->lchild = Node->rchild = NULL;
	return Node;
}
void insert(node* &root, int v){
	if(root == NULL){
		root = newNode(v);
		return;
	}
	if(abs(v) > abs(root->v)) insert(root->rchild, v);
	else if(abs(v) < abs(root->v)) insert(root->lchild, v);
}
bool judge(node* root){
	if(root == NULL) return true;
	if(root != NULL){
		if(root->v < 0){
			if(root->lchild != NULL){
				if(root->lchild->v < 0) return false;
			}
			if(root->rchild != NULL){
				if(root->rchild->v < 0) return false;
			}
		}
	}
	return judge(root->lchild) && judge(root->rchild);//beautiful
}
int getNum(node* root){
	if(root == NULL) return 0;
	int l = getNum(root->lchild);
	int r = getNum(root->rchild);
	return root->v > 0 ? max(l, r) + 1: max(l, r);//beautiful
}
bool judge1(node* root){
	if(root == NULL) return true;
	int l = getNum(root->lchild);
	int r = getNum(root->rchild);
	if(l != r) return false;
	return judge1(root->lchild) && judge1(root->rchild);//beautiful
}
int main()
{
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> m;
		int t, flag = 1;
		node* root = NULL;
		for(int i = 0; i < m; i++){
			cin >> t;
			insert(root, t);
			if(i == 0 && t < 0) flag = 0;
		}
		if(flag == 0 || !judge(root) || !judge1(root)) cout << "No" << endl;
		else cout << "Yes" << endl;	
	}
	return 0;
} 
