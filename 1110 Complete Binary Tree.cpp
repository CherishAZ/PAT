#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int n, lastnode, root = 0;
struct tree{
	int lchild = -1, rchild = -1;
}tt[101];
bool flag[101] = {false};
bool isBinaryTree(int root){
	queue<tree> q;
	q.push(tt[root]);
	int lack = 0, num = 1;
	while(!q.empty()){
		tree t1 = q.front();
		q.pop();
		if(t1.lchild != -1){
			if(lack == 1) break;
			q.push(tt[t1.lchild]);
			num++;
			if(num == n) lastnode = t1.lchild;	
		}else lack = 1;
		if(t1.rchild != -1){
			if(lack == 1) break;
			q.push(tt[t1.rchild]);
			num++;
			if(num == n) lastnode = t1.rchild;	
		}else lack = 1;
	}
	if(num == n) return true;
	else return false;
}
int main()
{
	string s1, s2;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s1 >> s2;
		if(s1 != "-"){
			tt[i].lchild = stoi(s1);
			flag[stoi(s1)] = 1;
		}
		if(s2 != "-"){
			tt[i].rchild = stoi(s2);
			flag[stoi(s2)] = 1;
		}
	}
	while(flag[root]) root++;
	if(isBinaryTree(root)) printf("YES %d\n", lastnode);
	else printf("NO %d\n", root);
	return 0;
} 
