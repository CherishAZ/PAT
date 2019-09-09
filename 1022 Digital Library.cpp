#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<string, vector<int> > mm[6];
int main()
{
	int n, m, temp, id;
	scanf("%d", &n);
	string s, s1, s2, s3, s4, s5;
	for(int i = 0; i < n; i++){
		int pos = 0, pos1 = 0;
		scanf("%d", &id);
		getchar();
		getline(cin, s1);
		mm[1][s1].push_back(id);
		
		getline(cin, s2);
		mm[2][s2].push_back(id);
		
		getline(cin, s3);
		for(int j = 0; j < s3.length(); j++){
			if(s3[j] == ' '){
				mm[3][s3.substr(pos1, j - pos1)].push_back(id);
				pos1 = j + 1;
			} 
		}
		mm[3][s3.substr(pos1)].push_back(id); 
		getline(cin, s4);
		mm[4][s4].push_back(id);
		cin >> s5;
		mm[5][s5].push_back(id);
	}
	scanf("%d", &m);
	getchar();
	for(int i = 0; i < m; i++){
		getline(cin, s);
		temp = s[0] - '0';
		s1 = s.substr(3);
		cout << s << endl;
		if(mm[temp][s1].size() != 0){
			sort(mm[temp][s1].begin(), mm[temp][s1].end());
			for(int j = 0; j < mm[temp][s1].size(); j++) printf("%07d\n", mm[temp][s1][j]);	
		}
		else printf("Not Found\n");
	}
	return 0;
}
/*
3
1111111
The Testing Book
Yue Chen
test
ZUCS Print
2011
3333333
Another Testing Book
Yue Chen
test code sort keywords
ZUCS Print2
2012
2222222
The Testing Book
CYLL
keywords debug book
ZUCS Print2
2011
6
1: The Testing Book
2: Yue Chen
3: keywords
4: ZUCS Print
5: 2011
3: blablabla
*/
