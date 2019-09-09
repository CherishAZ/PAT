#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	string s = to_string(n);
	int count = 0, len = s.length(); //the length of string
	
	for(int i = len - 1; i >= 0; i--){
		int m = s[i] - '0';
		int left = n / pow(10, len - i);
		int r = pow(10, len - i - 1);
		int right = n % r;
		if(m == 0) count += left * pow(10, len - i - 1);
		if(m == 1) count += left * pow(10, len - i - 1) + right + 1;
		if(m > 1) count += (left + 1) * pow(10, len - i - 1); 
	} 
	cout << count;
	return 0;
	
} 
