#include <iostream>
#include <string>
using namespace std;

int mp[2010] = {0};
int main()
{
	string s , m = "~#";//由于第一个和最后一个字符都是#号，且也需要搜索回文，
						//为了防止越界，我们还需要在首尾再加上非#号字符，
						//实际操作时我们只需给开头加上个非#号字符，
						//结尾不用加的原因是字符串的结尾标识为'\0'，等于默认加过了。
	getline(cin, s);
	for(int i = 0; i < s.length(); i++)
	{
		m += s[i];
		m += '#';
	}
	int mx = 0, id = 0, ans = 1;//边界与中心点 
	for(int i = 0; i < m.length(); i++)
	{
		mp[i] = mx > i ? min(mp[2 * id - i], mx - i) : 1;
		while(m[i + mp[i]] == m[i - mp[i]]) mp[i]++;
		if( i + mp[i] > mx)
		{
			mx = i + mp[i];
			id = i;
		}
		ans = max(ans, mp[i]);
	}
	cout << ans - 1;
	return 0;
 } 
