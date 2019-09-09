//语法树，右子树不为空为操作符 
#include <iostream>
using namespace std;
const int M  = 30;

struct node{
	int v, lchild, rchild;
	string str;
	bool isop;
}nn[M];
//中序遍历做了一点改变 
void InOrder(int root){
	if(root == -1) return;
	if(nn[nn[root].lchild].isop == 1){
		cout << "(";
		InOrder(nn[root].lchild);
		cout << ")";
	}else InOrder(nn[root].lchild);
	cout << nn[root].str;
	if(nn[nn[root].rchild].isop == 1){
		cout << "(";
		InOrder(nn[root].rchild);
		cout << ")";
	}else InOrder(nn[root].rchild);
	
}
bool vis[M] = {false};
int main()
{
	int n, root = 1;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> nn[i].str >> nn[i].lchild >> nn[i].rchild;
		if(nn[i].rchild != -1) nn[i].isop = 1;
		else nn[i].isop = 0;
		if(nn[i].lchild != -1) vis[nn[i].lchild] = true;
		if(nn[i].rchild != -1) vis[nn[i].rchild] = true;
	}
	for(root; root <= n; root++){
		if(!vis[root]) break;
	}
	InOrder(root);
	return 0;
}
