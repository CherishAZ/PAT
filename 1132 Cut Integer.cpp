#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int  num , n, t, temp, s1, s2;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> t;
		num = 0;
		temp = t;
		while(temp){
			num++;
			temp /= 10;
		}
		temp = pow(10, num / 2);
		s1 = t / temp;
		s2 = t % temp;
		if(s2 == 0) cout << "No" << endl;
		else{
			if(t % (s1 * s2) == 0) cout << "Yes" << endl;
		    else cout << "No" << endl;
		}	
	}
	return 0;
}
