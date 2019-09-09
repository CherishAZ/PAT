#include <iostream>
#include <stack>
using namespace std;

int arr[1010];
stack<int> st;
int main()
{
	int c, n, m;
	cin >> c >> n >> m;
	while(m--){
		while(!st.empty()) st.pop();
		for(int i = 1; i <= n; i++)	cin >> arr[i];
		int cur = 1;
		bool flag = true;
		for(int i = 1; i <= n; i++){
			st.push(i);
			if(st.size() > c){
				flag = false;
				break;
			}
			while(!st.empty() && st.top() == arr[cur]){
				st.pop();
				cur++;
			}
		}
		if(st.empty() == true && flag == true) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
} 
