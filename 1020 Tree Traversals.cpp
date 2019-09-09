#include <iostream>
#include <queue>
using namespace std;

int po[50], io[50], num = 0, n;
struct node{
	int val;
	node *lchild, *rchild;//�������� 
};
node* create(int pl, int pr, int il, int ir){
	if(pl > pr) return NULL;
	node* Node = new node;
	Node->val = po[pr];
	int  k;
	for(k = il; k <= ir; k++)
	if(io[k] == po[pr]) break;
	int dis = k - il;
	Node->lchild = create(pl, pl + dis - 1, il, k - 1);
	Node->rchild = create(pl + dis , pr - 1, k + 1, ir);//ע��ÿ�α仯������� 
	return Node;
}
//��α��� 
void LayerOrder(node* t){
	queue<node*> q;//��node* ����ͨ����ַ�޸ĸ�ԭԪ�� 
	q.push(t);
	while(!q.empty()){
		node* front = q.front();
		q.pop();
		printf("%d", front->val);
		num++;
		if(num < n) printf(" ");
		if(front->lchild != NULL) q.push(front->lchild);
		if(front->rchild != NULL) q.push(front->rchild);
	}
}
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &po[i]);
	for(int i = 0; i < n; i++) scanf("%d", &io[i]);
	node* t1 = new node;
	t1 = create(0, n - 1, 0, n - 1);
	LayerOrder(t1);
	return 0;
}
