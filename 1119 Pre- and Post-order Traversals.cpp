#include <iostream>
#include <vector>
using namespace std;
const int M = 101;

int n, pre[M], post[M], flag = 0;
struct node{
	node *lchild, *rchild;
	int v;
};
vector<int> ss;
void inOrder(node* root){
	if(root == NULL) return;
	inOrder(root->lchild);
	ss.emplace_back(root->v);
	inOrder(root->rchild);
}
node* create(int prel, int prer, int postl, int postr){
	if(prel > prer) return NULL;
	node* root = new node;
	root->v = pre[prel];
	if(prel == prer){
		root->lchild = NULL;
		root->rchild = NULL;
		return root;
	}
	int k;
	for(k = postl; k <= postr; k++){
		if(post[k] == pre[prel + 1]) break;
	}
	if((k - postl)  == (prer - prel + 1)) flag = 1;
	root->lchild = create(prel + 1, prel + k - postl + 1, postl, k - 1);
	root->rchild = create(prel + k - postl + 2, prer, k + 1, postr - 1);
	return root;
}
int main()
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> pre[i];
	for(int i = 0; i < n; i++) cin >> post[i];
	node* root = create(0, n - 1, 0, n - 1);
	if(flag) cout << "No" << endl;
	else cout << "Yes" << endl;
	inOrder(root);
	for(int i = 0; i < ss.size(); i++){
		cout << ss[i];
		if(i != ss.size() - 1) cout << " ";
	}
	cout << endl;
	return 0;
}
