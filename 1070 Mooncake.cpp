#include <iostream>
using namespace std;

int main()
{
	int n;
	float d;
	cin>>n>>d;
	float money = 0;
	float num[n],price[n];
	for(int i = 0;i < n; i++)
	cin >> num[i];
	for(int i = 0;i < n; i++)
	cin >> price[i];
	float u_price[n];
	float bal = d;
	for(int i=0; i < n; i++)
	u_price[i] = price[i] / num[i];
	int count = n;
	while (bal > 0 && count)
	{
		float temp = u_price[0];
		int flag = 0;
		for (int i = 1; i < n; i++)
		{
			if (u_price[i] > temp)
			{temp = u_price[i];
			flag = i;}
		}
		if(bal <= num[flag])
		{
			money +=  u_price[flag] * bal;
			break;
		}
		else
		money += price[flag];
		
		bal = bal - num[flag];
		u_price[flag] = -1;
		count--;
	}
	printf("%.2f",money);
	return 0;		
}
