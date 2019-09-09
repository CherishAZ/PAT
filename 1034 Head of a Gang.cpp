#include <iostream>
#include <cstring>
#include <map>
#include <set>
using namespace std;
const int M = 26 * 26 * 26 + 10;

map<string ,int> mm, mm1;//mm权重和string, mm1string和hash 
map<int, string> mm2;
set<string> ss, ss_output;
int father[M], num[M] = {0}, sumw[M] = {0}, maxString[M] = {0};
bool isRoot[M] = {false};
int s2i(string s){
	int sum = 0;
	for(int i = 0; i < s.length(); i++) sum = sum * 26 + (s[i] - 'A');
	return sum + 1;
}
void init(){
	for(int i = 1; i <= M; i++) father[i] = i;
}
int findFather(int x){
	int a = x;
	while(x != father[x]) x = father[x];
	//压缩
	while( a != father[a]){
		int z = a;
		a = father[a];
		father[z] = x;
	} 
	return x;
}
void Union(int a, int b){
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB) father[faA] = faB;
}
int main()
{
	init();
	int n, k, w;//block为块数， ans为符合要求的块数 
	scanf("%d%d", &n, &k);
	string s1, s2;
	for(int i = 0; i < n; i++){
		cin >> s1 >> s2 >> w;
		mm[s1] += w;
		mm[s2] += w;
		ss.insert(s1);
		ss.insert(s2);//ss来得到出现过的字符串 
		int a = s2i(s1);
		int b = s2i(s2);
		mm1[s1] = a;
		mm1[s2] = b;
		mm2[a] = s1;
		mm2[b] = s2;
		Union(a, b);
	}
	for(auto it : ss){
		int w = mm[it];
		int temp = findFather(mm1[it]);
		if( w > maxString[temp]) maxString[temp] = w;
		isRoot[temp] = true;
		num[temp]++;
		sumw[temp] += w;
	}
	for(auto it : ss){
		int temp = findFather(mm1[it]);
		if(isRoot[temp] && num[temp] > 2){
			if(sumw[temp] / 2 > k && mm[it] == maxString[temp]){
				ss_output.insert(it);
			}
		} 
	}
	cout << ss_output.size() << endl;
	for(auto it : ss_output){
		cout << it << " " << num[findFather(mm1[it])] << endl;
	}
}

/*
8 59
AAA BBB 10
BBB AAA 20
AAA DDD 40
CCC EEE 5
EEE CCC 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
*/

