#include <iostream>
using namespace std;
const int M = 50010;

int pre[M], in[M];
struct node{
	node *lchild, *rchild;
	int v;
};
node* create(int preL, int preR, int inL, int inR){
	if(preL > preR) return NULL;
	node* root = new node;
	root->v = pre[preL];
	int k;
	for(k = inL; k <= inR; k++){//<=inR
		if(in[k] == pre[preL]) break;
	} 
	int numLeft = k - inL;
	root->lchild = create(preL + 1, preL + numLeft, inL, k - 1);
	root->rchild = create(preL + numLeft + 1, preR, k + 1, inR);
	return root;
}
int postOrder(node* root){
	if(root->lchild != NULL) return postOrder(root->lchild);
	else{
		if(root->rchild != NULL) return postOrder(root->rchild);
		else return root->v;
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &pre[i]);
	for(int i = 0; i < n; i++) scanf("%d", &in[i]);
	node* root = create(0, n - 1, 0, n - 1);
	int v = postOrder(root);
	printf("%d", v);
	return 0;
} 
