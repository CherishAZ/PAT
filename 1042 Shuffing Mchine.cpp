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
		start[i] = end[i];//���ϸ������� 
	}
	}
	for(int i = 1; i <= N; i++)
	{
		if(i != 1) cout << " " ;
		end[i]--;// ��Χ1-13 ��Ϊ 0-12 
		printf("%c%d", s[end[i]/ 13], end[i] % 13 + 1);
	}
	return 0;
}
