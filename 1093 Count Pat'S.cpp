#include <iostream>
using namespace std;
const int M = 100010;
const int MOD = 1000000007;
int leftNumP[M] = {0};

int main()
{
	string s;
	cin >> s;
	for(int i = 0; i < s.length(); i++){
		if( i > 0){
			leftNumP[i] = leftNumP[i - 1];
		}
		if(s[i] == 'P') leftNumP[i]++;
	}
	int ans = 0, rightNumT = 0;
	for(int i = s.length() - 1; i >= 0; i--){
		if(s[i] == 'T'){
			rightNumT++;
		}else if( s[i] == 'A'){
			ans = (ans + leftNumP[i] * rightNumT) % MOD;
		}
	}
	cout << ans;
	return 0;
}
