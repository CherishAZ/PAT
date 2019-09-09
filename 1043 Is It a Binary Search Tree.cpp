#include <iostream>
#include <vector>
using namespace std;

int a[1010];
struct node{
	int val;
	node *lchild, *rchild;
};
void insert(node* &root, int x){
	if(root == NULL){
		root = new node;
		root->val = x;
		root->lchild = root->rchild = NULL;
		return;
	}
	if(x < root->val) insert(root->lchild, x);
	else insert(root->rchild, x);
}
void preorder(node* root, vector<int> &v){
	if(root == NULL) return;
	v.push_back(root->val);
	preorder(root->lchild, v);
	preorder(root->rchild, v);
}
void preorderMirror(node* root, vector<int> &v){
	if(root == NULL) return;
	v.push_back(root->val);
	preorderMirror(root->rchild, v);
	preorderMirror(root->lchild, v);
}
void postorder(node *root, vector<int> &v){
	if(root == NULL) return;
	postorder(root->lchild, v);
	postorder(root->rchild, v);
	v.push_back(root->val);
}
void postorderMirror(node* root, vector<int> &v){
	if(root == NULL) return;
	postorderMirror(root->lchild, v);
	postorderMirror(root->rchild, v);
	v.push_back(root->val);
}
vector<int> origin, pre, preM, post, postM;
int main()
{
	int n, data;
	node* root = NULL;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &data);
		origin.push_back(data);
		insert(root, data);
	} 
	preorder(root, pre);
	preorderMirror(root, preM);
	postorder(root, post);
	postorderMirror(root, postM);
	if(origin == pre){
		printf("YES\n");
		for(int i = 0; i < post.size(); i++){
			printf("%d", post[i]); 
			if(i != post.size() - 1) printf(" ");
		}
	}else if(origin == preM){
		printf("YES\n");
		for(int i = 0; i < postM.size(); i++){
			printf("%d", postM[i]);
			if(i != postM.size() - 1) printf(" ");
		}
	}else printf("NO\n");
	return 0;
}

