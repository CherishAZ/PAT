#include <iostream>
using namespace std;

int main()
{
	const int N = 54;
	int start[N], end[N], next[N];
	int n;
	cin >> n;
	char s[] = {'S', 'H', 'C', 'D', 'J'};
	for(int i = 1; i <= N; i++)
	{
		start[i] = i;
		cin >> next[i];
	}
	while(n--){
	for(int i = 1; i <= N; i++)
	{
		end[next[i]] = start[i];
	}
	for(int i = 1; i <= N; i++)
	{
		start[i] = end[i];//不断更新数组 
	}
	}
	for(int i = 1; i <= N; i++)
	{
		if(i != 1) cout << " " ;
		end[i]--;// 范围1-13 变为 0-12 
		printf("%c%d", s[end[i]/ 13], end[i] % 13 + 1);
	}
	return 0;
}
