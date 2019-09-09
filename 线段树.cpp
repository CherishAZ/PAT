#include <iostream>
using namespace std;
const int M = 100;

void build_tree(int arr[], int tree[], int node , int start, int end){
	if(start == end){
		tree[node] = arr[start];
	}else{
		int mid = (start + end) / 2;
		int left_node = 2 * node + 1;
		int right_node = 2 * node + 2;
		build_tree(arr, tree, left_node, start, mid);
		build_tree(arr, tree, right_node, mid + 1, end);
		tree[node] = tree[left_node] + tree[right_node];
	}
}

void update_tree(int arr[], int tree[], int node, int start, int end, int idx, int val){
	if(start == end){
		arr[idx] = val;
		tree[node] = val;
	}else{
		int mid = (start + end) / 2;
		int left_node = 2 * node + 1;
		int right_node = 2 * node + 2;
		if(idx >= start && idx <= mid){
			update_tree(arr, tree, left_node, start, mid, idx, val);
		}else{
			update_tree(arr, tree, right_node, mid + 1, end, idx, val);
		}
		tree[node] = tree[left_node] + tree[right_node];
	}
}
int query_tree(int arr[], int tree[], int node, int start, int end, int L, int R){
	cout << start << " " << end << endl;
	if(start > R || L > end){
		return 0;
	}else if(start == end || (L <= start && end <= R)){
		return tree[node];
	}else{
		int mid = (start + end) / 2;
		int left_node = 2 * node + 1;
		int right_node = 2 * node + 2;
		int sum_left = query_tree(arr, tree, left_node, start, mid, L, R);
		int sum_right = query_tree(arr, tree, right_node, mid + 1, end, L, R);
		return sum_left + sum_right;
	}
}
int main(){
	int arr[] = {1, 3, 5, 7, 9, 11};
	int tree[M] = {0};
	build_tree(arr, tree, 0, 0, 5);
	for(int i = 0; i < 15; i++) cout << i << "= " << tree[i] << endl;
	cout << endl;
	update_tree(arr, tree, 0, 0, 5, 4, 6);
	for(int i = 0; i < 15; i++) cout << i << "= " << tree[i] << endl;
	cout << query_tree(arr, tree, 0, 0, 5, 2, 5);
	return 0;
}
