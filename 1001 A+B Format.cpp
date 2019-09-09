#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int m,n;
	cin>>m>>n;
	int sum1=m+n;
	int count=-1;
	int sum=sum1;
	while(sum1)
	{count++;
	sum1/=1000;}
	if(sum==0)
	cout<<sum;
	else if(count==0)
	cout<<sum;
	else if(count==1)
	printf("%d,%03d",sum/1000,abs(sum%1000));
	else if(count==2)
	printf("%d,%03d,%03d",sum/1000000,abs(sum/1000-sum/1000000*1000),abs(sum%1000));
}
