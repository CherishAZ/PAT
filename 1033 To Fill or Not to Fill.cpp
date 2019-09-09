#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1 << 30;
struct station{
	double price, dis;
}st[510];
int cmp(station a, station b){
	return a.dis < b.dis;
}
int main()
{
	int n;
	double Cmax, D, Davg;
	cin >> Cmax >> D >> Davg >> n;
	for(int i = 0; i < n; i++){
		cin >> st[i].price >> st[i].dis;
	}
	st[n].price = 0;
	st[n].dis = D;
	sort(st, st + n, cmp);
	if(st[0].dis != 0){
		cout << "The maximum travel distance = 0.00" << endl;
	}else{
		int now = 0;
		double ans = 0, nowTank = 0, Max = Cmax * Davg;
		while(now < n){
			int k = -1;
			double priceMin = INF;
			for(int i = now + 1; i <= n && (st[i].dis - st[now].dis) <= Max; i++){
				if(st[i].price < priceMin){
					priceMin = st[i].price;
					k = i;
				}
				if(priceMin < st[now].price) break;
			}
		if( k == -1) break;
		double need = (st[k].dis - st[now].dis) / Davg;
		if(priceMin < st[now].price){
			if(nowTank < need){
				ans += (need - nowTank) * st[now].price;
				nowTank = 0;
			}else{
				nowTank -= need;
			}
		}else{
			ans += (Cmax - nowTank) * st[now].price;
			nowTank = Cmax - need;
		}
		now = k;	
	}
	if(now == n) printf("%.2f\n", ans);
	else printf("The maximum travel distance = %.2f\n", st[now].dis + Max);
	}
	return 0;
}
  
