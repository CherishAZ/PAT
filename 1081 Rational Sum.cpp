#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
struct Fraction{
	ll up, down;
}ff[110], rrr;
ll gcd(ll a, ll b)
{
	return !b ? a : gcd(b, a % b);
}
Fraction reduction(Fraction rr)
{
	if(rr.down < 0){
		rr.down = -rr.down;
		rr.up = -rr.up;
	}
	if(rr.up == 0) rr.down = 1;
	else{
		int d = gcd(abs(rr.up), abs(rr.down));
		rr.up /= d;
		rr.down /= d;
	}
	return rr;
}
Fraction add(Fraction f1, Fraction f2)
{
	Fraction result;
	result.up = f1.up * f2.down + f2.up * f1.down;
	result.down = f1.down * f2.down;
	return reduction(result);
}
void showResult(Fraction r){
	r = reduction(r);
	if(r.down == 1) printf("%lld\n", r.up);
	else if(abs(r.up) > r.down) printf("%lld %lld/%lld\n", r.up / r.down, abs(r.up) % r.down, r.down);
	else printf("%lld/%lld\n", r.up, r.down);
}
int main()
{
	int n;
	scanf("%d", &n);
	rrr.up = 0;
	rrr.down = 1;
	for(int i = 0; i < n; i++){
		scanf("%lld/%lld", &ff[i].up, &ff[i].down);
		rrr = add(ff[i], rrr);
	}
	showResult(rrr);
	return 0;
}
