#include <iostream>
using namespace std;

void to(int x){
	char ch[]= {'A', 'B', 'C'};
	int r[2] = {x % 13, x / 13}, i = 0;
	if(r[1] > 9)
	cout << ch[r[1] - 10];
	else
	cout << r[1];
	if(r[0] > 9)
	cout << ch[r[0] - 10];
	else
	cout << r[0];
}
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	cout << "#";
	to(a);
	to(b);
	to(c);
	return 0;
}
