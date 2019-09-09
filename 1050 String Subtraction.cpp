#include <iostream>
using namespace std;

int num[200] = {0};
int main()
{
    string str, str1;
    getline(cin, str);
    getline(cin, str1);
    for(int i = 0; i < str.length(); i++){
        num[str[i]]++;
    }
    for(int i = 0;i < str1.length(); i++){
        num[str1[i]] = 0;
    }
    for(int i = 0;i < str.length(); i++){
        if(num[str[i]] != 0) cout << str[i];
    }
    return 0;
}
