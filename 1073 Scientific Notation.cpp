#include <iostream>
#include <cstring>
using namespace std;

int stringTonum(string str){
	int sum = 0;
	for(int i = 0; i < str.length(); i++){
		sum = sum * 10 + str[i] - '0';
	}
	return sum;
}
int main()
{
	string s;
	cin >> s;
	int pos = s.find('E');
	int num = stringTonum(s.substr(pos + 2));
	if(s[0] == '-') cout << s[0];
	if(s[pos + 1] == '-'){
		if(num != 0){
			cout << "0.";
			for(int i = 0; i < num - 1; i++) cout << 0;
			for(int i = 1; i < pos; i++){
				if(s[i] >= '0' && s[i] <= '9') cout << s[i];
			}
		}else{
			for(int i = 1; i < pos; i++){
				cout << s[i];
			}
		}	
	}else{
		if(pos - 3 <= num){
			for(int i = 1; i < pos; i++){
				if(s[i] >= '0' && s[i] <= '9') cout << s[i];
			}
			int temp = num + 3 - pos;
			while(temp--) cout << 0;
		}else{
			for(int i = 1; i <= num + 2; i++){
				if(s[i] >= '0' && s[i] <= '9') cout << s[i];
			}
			cout << ".";
			for(int i = num + 3; i < pos; i++){
				if(s[i] >= '0' && s[i] <= '9') cout << s[i];
			}
		}
	}	
	return 0;
} 
