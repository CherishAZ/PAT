#include <iostream>
#include <stack>
using namespace std;

struct node{
	int val;
	node *lchild, *rchild;
};
int n, a[50], b[50], num = 0, num1= 0;
node* create(int prel, int prer, int il, int ir){
	if(prer < prel) return NULL;
	node* root = new node;
	root->val = b[prel];
	int k;
	for(k = il; k <= ir; k++)
	if(a[k] == b[prel]) break;
	int dis = k - il;
	root->lchild = create(prel + 1, prel + dis, il, k - 1);
	root->rchild = create(prel + dis + 1, prer, k + 1, ir);
	return root;
}
void PostOrder(node* r){
	if(r == NULL) return;
	PostOrder(r->lchild);
	PostOrder(r->rchild);
	printf("%d", r->val);
	num--;
	if(num > 0) printf(" ");
}
int main()
{
	scanf("%d", &n);
	getchar();
	string s;
	int temp;
	stack<int> ss;
	for(int i = 0; i < 2 * n; i++){
		cin >> s;
		if(s == "Push"){
			cin >> b[num1];
			ss.push(b[num1]);
			num1++;
		}
		else {
			a[num++] = ss.top();
			ss.pop();
		}
	}
	node* r = create(0, n - 1, 0, n - 1);
	PostOrder(r);
	return 0;
} 
