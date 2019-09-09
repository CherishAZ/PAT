#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int data[100010], next1[100010];
int main()
{
	int t, s1, s2, n;
	char c;
	set<int> ss1;
	scanf("%d %d %d", &s1, &s2, &n);
	for(int i = 0; i < n; i++){
	 cin >> t >> c; 
	 cin >> next1[t];
	}
	while(s1 != -1){
		ss1.insert(s1);
		s1 = next1[s1];
	}
	while(s2 != -1){
		if(ss1.find(s2) != ss1.end()) break;
		else s2 = next1[s2];
	}
	if(s2 != -1) printf("%05d", s2);
	else printf("-1");
	return 0;
}
