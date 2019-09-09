#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int main()
{
	string s;
	cin >> s;
	string pair[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	vector<int> ss;
	int sum = 0;
	for(int i = 0; i < s.length(); i++)
	sum += (s[i] - '0');
	while(sum)
	{
		ss.push_back(sum % 10);
		sum /= 10;
	}
	if(ss.size() == 0)//·ÀÖ¹¶Î´íÎó 
	cout << "zero";
	else{
	for(int i = ss.size() - 1; i > 0; i--)
	{
		cout << pair[ss[i]] << " ";
	}
	cout << pair[ss[0]];}
	return 0;
 } 
