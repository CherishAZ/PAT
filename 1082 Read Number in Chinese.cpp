#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

string num[10] = { "ling","yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
string c[6] = { "Ge","Shi", "Bai", "Qian", "Yi", "Wan" };
int J[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
int main()
{
	int n;
	cin >> n;
	if(n == 0){
		cout << "ling";
		return 0;
	} 
	if(n < 0){
		cout << "Fu ";
		n = -n;
	}
	int part[3];
	part[0] = n / 100000000;
	part[1] = (n % 100000000) / 10000;
	part[2] = n % 10000;
	bool zero = false;
	int printCnt = 0;
	for(int i = 0; i < 3; i++){
		int temp = part[i];
		for(int j = 3; j >= 0; j--){
			int curPos = 8 - i * 4 +j;
			if(curPos >= 9) continue;
			int cur = (temp / J[j]) % 10;
			if(cur != 0){
				if(zero){
					printCnt++ == 0? cout << "ling" : cout << " ling";
					zero = false;
				}
				if(j == 0)
					printCnt++ == 0? cout << num[cur] : cout << " " << num[cur];
				else
					printCnt++ == 0? cout << num[cur] << " " << c[j] : cout << " " << num[cur] << " " << c[j];
			}
			else{
				if( !zero && j != 0 && n / J[curPos] >= 10) zero = true;
			}
			}
			if( i != 2 && part[i] > 0) cout << " " << c[i + 4];
			
		}
	

	return 0;
}
