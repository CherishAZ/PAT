#include <iostream>
#include <string>
using namespace std;

int mp[2010] = {0};
int main()
{
	string s , m = "~#";//���ڵ�һ�������һ���ַ�����#�ţ���Ҳ��Ҫ�������ģ�
						//Ϊ�˷�ֹԽ�磬���ǻ���Ҫ����β�ټ��Ϸ�#���ַ���
						//ʵ�ʲ���ʱ����ֻ�����ͷ���ϸ���#���ַ���
						//��β���üӵ�ԭ�����ַ����Ľ�β��ʶΪ'\0'������Ĭ�ϼӹ��ˡ�
	getline(cin, s);
	for(int i = 0; i < s.length(); i++)
	{
		m += s[i];
		m += '#';
	}
	int mx = 0, id = 0, ans = 1;//�߽������ĵ� 
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
