#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct bign{
	int d[1000], len;
	bign(){
		memset(d, 0, sizeof(d));
		len = 0;
	}
};
bign change(string s){
	bign a;
	a.len = s.length();
	for(int i = 0; i < a.len; i++) a.d[i] = s[a.len - i - 1] - '0';
	return a;
}
bign add(bign a, bign b){
	bign c;
	int carry = 0;
	for(int i = 0; i < a.len || i < b.len; i++){
		int temp = a.d[i] + b.d[i] + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	if(carry != 0) c.d[c.len++] = carry;
	return c;
}
bool judge(bign a){
	for(int i = 0; i <= a.len / 2; i++){
		if(a.d[i] != a.d[a.len - i - 1]) return false;
	}
	return true;
}
void print(bign a){
	for(int i = a.len - 1; i >= 0; i--) cout << a.d[i];
	cout << endl;	
}
int main()
{
	string s;
	int t, k = 0;
	cin >> s >> t;
	bign a = change(s);
	while( k < t && !judge(a)){
		bign b = a;
		reverse(b.d, b.d + b.len);
		a = add(a, b);
		k++;
	}
	print(a);
	cout << k << endl;
	return 0;
}
