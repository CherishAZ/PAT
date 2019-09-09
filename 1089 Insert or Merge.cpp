#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> s1, s2, s3;
int n;
int insertionSort(vector<int> ss){
	int flag = 0;
	for(int i = 1; i < n; i++){
		if(ss == s2 && i != 1){
			flag = i;
			break;
		}
		sort(ss.begin(), ss.begin() + i);
	}
	return flag;
}
void mergeSort(vector<int> ss){
	bool flag = false;
	for(int step = 2; step / 2 <= n; step *= 2){
		if(step != 2 && ss == s2) flag = true;
		for(int i = 0; i < n; i += step) sort(ss.begin() + i, ss.begin() + min(i + step, n));
		if(flag){
			for(int i = 0; i < ss.size(); i++){
				cout << ss[i];
				if(i != ss.size() - 1) cout << " ";	
			}
			return;
		}
	}
}
int main()
{
	int t , flag = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> t;
		s1.push_back(t);
	}
	for(int i = 0; i < n; i++){
		cin >> t;
		s2.push_back(t); 
	}
	s3 = s1;
	flag = insertionSort(s3);
	if(flag != 0){
		cout << "Insertion Sort" << endl;
		sort(s3.begin(), s3.begin() + flag + 1);
		for(int i = 0; i < s3.size(); i++){
			cout << s3[i];
			if(i != s3.size() - 1) cout << " ";
		}
	}else{
		cout << "Merge Sort" << endl;
		mergeSort(s1);
	}
	return 0;
}
