#include <iostream>
#include <cstring>
#include <map>
#include <cmath>
using namespace std;
typedef long long  ll;

ll getNum(string s, ll r){
	ll sum = 0;
	for(int i = 0; i < s.length(); i++){
		if('0' <= s[i] && s[i] <= '9')
		sum = sum * r + s[i] - '0';
		else if('a' <= s[i] && s[i] <= 'z')
		sum = sum * r + s[i] - 'a' + 10;
		if(sum < 0) return -1;//判断溢出，或者使用unsigned long long 
	}
	return sum;
}
int getBig(string s){
	int rr = 0;//至少多少进制
	for(int i = 0; i < s.length(); i++){
		if('0' <= s[i] && s[i] <= '9')
		rr = max(rr, s[i] - '0');
		else if('a' <= s[i] && s[i] <= 'z')
		rr = max(rr, s[i] - 'a' + 10);
	}
	return rr; 
}
ll getR(string s, ll rr, ll sum){
	ll len = s.length(), rmin = rr + 1, rmax = sum + 1, mid, s_temp = 0;
	while(rmin <= rmax){
		mid = rmin + (rmax - rmin) / 2;
		s_temp = getNum(s, mid);
		if(s_temp < 0){
			rmax = mid - 1;
			continue;
		}//判断一波溢出 
		if(s_temp == sum) return mid;
		if(s_temp < sum) rmin = mid + 1;
		else rmax = mid - 1;
	}
	return 0;
}
int main()
{
	string s1, s2;
	ll tag, r;
	cin >> s1 >> s2 >> tag >> r;
	ll sum = 0;
	if(tag == 1) sum = getNum(s1, r);
	else sum = getNum(s2, r);
	ll radix = 0, rr = 0; 
	if(tag == 1){
		rr = getBig(s2);
		if(rr != 0) radix = getR(s2, rr, sum);
	} 
	else if(tag == 2){
		rr = getBig(s1);
		if(rr != 0) radix = getR(s1, rr, sum);
	}
	if(radix == 0) cout << "Impossible" << endl;
	else cout << radix << endl;
	return 0;
}
