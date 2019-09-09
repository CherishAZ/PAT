#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

struct customer{
	string name;
	bool status;
	int month, dd, hh, mm;
}nn[1001], tt1, tt2;
int toll[25];
int cmp(customer nn1, customer nn2)
{
	if(nn1.name != nn2.name) return nn1.name < nn2.name;
	else if(nn1.month != nn1.month)	return nn1.month < nn2.month;
	else
	{
		if(nn1.dd != nn2.dd) return nn1.dd < nn2.dd;
		else
		{
			if(nn1.hh != nn2.hh)	return nn1.hh < nn2.hh;
			else return nn1.mm < nn2.mm;
		}
	}
}
void get_ans(int on, int off, int &time, int &money){//时间、钱通过time++来完成，从一 个时间加到另一个时间 
	tt1 = nn[on];
	tt2 = nn[off];
	while(tt1.dd < tt2.dd || tt1.hh < tt2.hh || tt1.mm < tt2.mm){
		time++;
		money += toll[tt1.hh];
		tt1.mm++;
		if(tt1.mm >= 60){
			tt1.mm = 0;
			tt1.hh++;
		}
		if(tt1.hh >= 24){
			tt1.hh = 0;
			tt1.dd++;
		}
	}
}
int main()
{
	int  k = 0, n;
	for(int i = 0; i < 24; i++) cin >> toll[i];
	cin >> n;
	string line;
	for(int i = 0; i < n; i++){	
		cin >> nn[i].name;
		scanf("%d:%d:%d:%d", &nn[i].month, &nn[i].dd, &nn[i].hh, &nn[i].mm); 
		cin >> line;
		if(line == "on-line") nn[i].status = true;
		else nn[i].status = false;
	}
	sort(nn, nn + n, cmp);
	int on = 0, off, next;//on 与 next来控制不同的id之间的输出 
	while(on < n){
		int needPrint = 0;//遇到online变1， 遇到offline为2，为 2才输出 
		next = on;
		while(next < n && nn[on].name == nn[next].name){
			if(needPrint == 0 && nn[next].status == true) needPrint = 1;
			else if(needPrint == 1 && nn[next].status == false) needPrint = 2;
			next++;
		}
		if(needPrint < 2){
			on = next;
			continue;
		}
		int AllMoney = 0;
		cout << nn[on].name;
		printf(" %02d\n", nn[on].month);
		while(on < next){
			while(on < next - 1 && !(nn[on].status == true && nn[on + 1].status == false)) on++;
			off = on + 1;
			if( off == next){
				on = next;
				break;
			}
			printf("%02d:%02d:%02d ", nn[on].dd, nn[on].hh, nn[on].mm);
			printf("%02d:%02d:%02d ", nn[off].dd, nn[off].hh, nn[off].mm);
			int time = 0, money = 0;
			get_ans(on, off, time, money);
			AllMoney += money;
			printf("%d $%.2f\n", time, money / 100.0);
			on = off + 1;
		}
		printf("Total amount: $%.2f\n", AllMoney / 100.0);
	}
	return 0;
 } 
