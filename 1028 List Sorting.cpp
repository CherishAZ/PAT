#include <iostream>
#include <algorithm>
using namespace std;

struct stu{
	string id, name;
	int grade;
}ss[100001];

int cmp1(stu s1, stu s2)
{
	return s1.id < s2.id;
}
int cmp2(stu s1, stu s2)
{
	return s1.name != s2.name ? s1.name < s2.name : s1.id < s2.id;
}
int cmp3(stu s1, stu s2)
{
	return s1.grade != s2.grade ? s1.grade < s2.grade : s1.id < s2.id;
}
int main()
{
	int n, c;
	cin >> n >> c;
	for(int i = 0; i < n; i++)
	cin >> ss[i].id >> ss[i].name >> ss[i].grade;
	switch(c){
		case 1: sort(ss, ss + n, cmp1); break;
		case 2: sort(ss, ss + n, cmp2); break;
		case 3: sort(ss, ss + n, cmp3); break;
		default : break;
	}
	for(int i = 0; i < n; i++)
	cout << ss[i].id << " " << ss[i].name << " " << ss[i].grade << endl;
	return 0;
 } 
