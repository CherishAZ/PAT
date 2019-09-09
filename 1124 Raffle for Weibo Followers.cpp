#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main()
{
	int m, n, s;
	cin >> m >> n >> s;
	vector<string> ss, ss1;
	map<string, int> mm1;
	string str;
	for(int i = 0; i < m; i++){
		cin >> str;
		ss.emplace_back(str);
		mm1[str] = 1;
	}
	for(int i = s - 1; i < m; i += n){
		if(mm1[ss[i]] == 1){
			ss1.emplace_back(ss[i]);
			mm1[ss[i]] = 2;
		}else{
			while(mm1[ss[i]] != 1 && i < m) i++;//while循环i写出来保险 
			if(i == m) break;
			ss1.emplace_back(ss[i]);
			mm1[ss[i]] = 2;
		}
	}
	if(ss1.size() == 0) cout << "Keep going..." << endl;
	else{
		for(int i = 0; i < ss1.size(); i++){
			cout << ss1[i] << endl;
		}
	}
	return 0;
}
