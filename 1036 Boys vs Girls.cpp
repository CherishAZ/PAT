#include <iostream>
using namespace std;

struct stu{
	string name, id;
	char sex;
	int s;
}ss[1001];
int main()
{
	int n;
	cin >> n;
	int m1 = 0, pos1 = -1, m2 = 100, pos2 = -1;
	for(int i = 0; i < n; i++)
	{
		cin >> ss[i].name >> ss[i].sex >> ss[i].id >> ss[i].s;
		if(ss[i].sex == 'F')
		{
			if(m1 < ss[i].s)
			{
				m1 = ss[i].s;
				pos1 = i;
			}
		}
		if(ss[i].sex == 'M')
		{
			if(m2 > ss[i].s)
			{
				m2 = ss[i].s;
				pos2 = i;
			}
		}
	}
	if(pos1 != -1)
	cout << ss[pos1].name << " " << ss[pos1].id << endl;
	else
	cout << "Absent" << endl;
	
	if(pos2 != -1)
	cout << ss[pos2].name << " " <<  ss[pos2].id << endl;
	else
	cout << "Absent" << endl;
	
	if(pos1 == -1 || pos2 == -1)
	cout << "NA";
	else
	cout << m1 - m2;
	return 0;
	
}
