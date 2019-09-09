#include <iostream>
using namespace std;
const int M = 110;

int n, post[M], in[M], layer[M];
struct node{
	node *lchild, *rchild;
	int v;
};
//后序+中序 
//node* create(int postl, int postr, int inl, int inr){
//	if(postl > postr) return NULL;
//	node* root = new node;
//	root->v = post[postr];
//	int k;
//	for(k = inl; k <= inr; k++){
//		if(in[k] == post[postr]) break;
//	}
//	int numleft = k - inl;
//	root->lchild = create(postl, postl + numleft - 1, inl, k - 1);
//	root->rchild = create(postl + numleft, postr - 1, k + 1, inr);
//	return root; 
//}
//层次+中序 
node* create(int layerL, int inl, int inr){
	if(inl > inr) return NULL;
	node* root = new node;
	int k, i, flag = 0;
	for(i = layerL; i < n; i++){
		for(k = inl; k <= inr; k++){
			if(in[k] == layer[i]){
				flag = 1; 
				break;
			} 
		}
		if(flag) break;
	}
	root->v = layer[i];
	root->lchild = create(layerL, inl, k - 1);
	root->rchild = create(layerL, k + 1, inr);
	return root; a
}
void preTraverse(node* root){
	if(root == NULL) return;
	cout << root->v << " ";
	preTraverse(root->lchild);
	preTraverse(root->rchild);
}
int main()
{
	cin >> n;
//	for(int i = 0; i < n; i++) cin >> post[i];
	for(int i = 0; i < n; i++) cin >> layer[i];
	for(int i = 0; i < n; i++) cin >> in[i];
//	node* root = create(0, n - 1, 0, n - 1);
	node* root = create(0, 0, n - 1);
	preTraverse(root);
	return 0;
} 
