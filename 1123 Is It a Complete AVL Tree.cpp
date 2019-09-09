#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, data[21];
struct node{
	int v, h;
	node *lchild, *rchild;
};
node* newNode(int v){
	node* Node = new node;
	Node->v = v;
	Node->h = 1;
	Node->rchild = Node->lchild = NULL;
	return Node;
}
int getHeight(node* root){
	if(root == NULL) return 0;
	return root->h;
}
int updateHeight(node* root){
	root->h =  max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}
int getBalanceFactor(node* root){
	return getHeight(root->lchild) - getHeight(root->rchild);
}
void L(node* &root){
	node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}
void R(node* &root){
	node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}
void insert(node* &root, int v){
	if(root == NULL){
		root = newNode(v);
		return;
	}
	if(v < root->v){
		insert(root->lchild, v);
		updateHeight(root);
		if(getBalanceFactor(root) == 2){
			if(getBalanceFactor(root->lchild) == 1){
				R(root);
			}else if(getBalanceFactor(root->lchild) == -1){
				L(root->lchild);
				R(root);
			}
		}
	}else if(v > root->v){
		insert(root->rchild, v);
		updateHeight(root);
		if(getBalanceFactor(root) == -2){
			if(getBalanceFactor(root->rchild) == -1){
				L(root);
			}else if(getBalanceFactor(root->rchild) == 1){
				R(root->rchild);
				L(root);
			}
		}
	}
}
node* create(int data[]){
	node* root = NULL;
	for(int i = 0; i < n; i++) insert(root, data[i]);
	return root;
}
vector<int> ss;
int lack = 0, iscomplete = 1;
void layerTraverse(node* root){
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* temp = q.front();
		ss.emplace_back(temp->v);
		q.pop();
		if(temp->lchild != NULL){
			q.push(temp->lchild);
			if(lack) iscomplete = 0;
		}else lack = 1;
		if(temp->rchild != NULL){
			q.push(temp->rchild);
			if(lack) iscomplete = 0;
		}else lack = 1;
	}
}
int main()
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> data[i];
	node* root = create(data);
	layerTraverse(root);
	for(int i = 0; i < ss.size() - 1; i++) cout << ss[i] << " ";
	cout << *ss.rbegin() << endl;
	if(iscomplete == 0) cout << "NO";
	else cout << "YES";
	return 0;
}
