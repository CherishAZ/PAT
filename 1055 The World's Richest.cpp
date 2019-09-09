#include <iostream>
#include <algorithm>
using namespace std;

struct people{
	string name;
	int age, w;
}pp[100010], valid[100010];
int cmp(people p1, people p2)
{
	if(p1.w != p2.w) return p1.w > p2.w;
	else 
	return (p1.age != p2.age) ? (p1.age < p2.age) : (p1.name < p2.name);
}
int Age[100010] = {0};
int main()
{
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++) 	cin >> pp[i].name >> pp[i].age >> pp[i].w;
	sort(pp, pp + n, cmp);
	int validNum = 0;
	for(int i = 0; i < n; i++){
		if(Age[pp[i].age] < 100){
			Age[pp[i].age]++;
			valid[validNum++] = pp[i];
		}
	}//预处理，同年龄100名外的排除 
	int num, amin, amax;
	for(int i = 1; i <= k; i++){
		cin >> num >> amin >> amax;
		cout << "Case #" << i << ":" << endl;
		int flag = 0;
		for(int j = 0; j < validNum && flag < num; j++){
			if(pp[j].age >= amin && pp[j].age <= amax){
			cout << valid[j].name << " " << valid[j].age << " " << valid[j].w << endl;
			flag++;
			}
		}
		if(flag == 0) cout << "None" << endl;
	}
	return 0;
}
