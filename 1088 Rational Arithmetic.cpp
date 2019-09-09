#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
struct Fraction{
	ll up, down;
}ff[2];
ll gcd(ll a, ll b){
	return !b ? a : gcd(b, a % b);
}//long long注意范围 (乘除可能溢出) 
Fraction reduction(Fraction r)
{
	if(r.down < 0){
		r.down = -r.down;
		r.up = -r.up;
	}
	if(r.up == 0) r.down = 1;
	else{
		int d = gcd(abs(r.up), abs(r.down));
		r.up /= d;
		r.down /= d;
	}
	return r;
}
//加法 
Fraction add(Fraction f1, Fraction f2){
	Fraction result;
	result.up = f1.up * f2.down + f2.up * f1.down;
	result.down = f1.down * f2.down;
	return reduction(result);
}
//减法 
Fraction mm(Fraction f1, Fraction f2){
	Fraction result;
	result.up = f1.up * f2.down - f1.down * f2.up;
	result.down = f1.down * f2.down;
	return reduction(result);
}
//乘法 
Fraction multiply(Fraction f1, Fraction f2){
	Fraction result;
	result.up = f1.up * f2.up;
	result.down = f1.down * f2.down;
	return reduction(result);
}
//除法 
Fraction div(Fraction f1, Fraction f2){
	Fraction result;
	result.up = f1.up * f2.down;
	result.down = f1.down * f2.up;
	return reduction(result);
}
void showResult(Fraction r){
	r = reduction(r);
	if(r.up < 0) printf("(");
	if(r.down == 1) printf("%lld", r.up);
	else if(abs(r.up) > r.down) printf("%lld %lld/%lld", r.up / r.down, abs(r.up) % r.down, r.down);
	else printf("%lld/%lld", r.up, r.down); 
	if(r.up < 0) printf(")");
}
int main()
{
	scanf("%lld/%lld", &ff[0].up, &ff[0].down);
	scanf("%lld/%lld", &ff[1].up, &ff[1].down);
	//add
	showResult(ff[0]);
	printf(" + ");
	showResult(ff[1]);
	printf(" = ");
	showResult(add(ff[0], ff[1]));
	printf("\n");
	//mm
	showResult(ff[0]);
	printf(" - ");
	showResult(ff[1]);
	printf(" = ");
	showResult(mm(ff[0], ff[1]));
	printf("\n");
	//multiply
	showResult(ff[0]);
	printf(" * ");
	showResult(ff[1]);
	printf(" = ");
	showResult(multiply(ff[0], ff[1]));
	printf("\n");
	//div
	showResult(ff[0]);
	printf(" / ");
	showResult(ff[1]);
	printf(" = ");
	if(ff[1].up == 0) printf("Inf");
	else showResult(div(ff[0], ff[1]));
	printf("\n");
	return 0;
}
