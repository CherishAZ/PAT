#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    while(n != 0){
        int a[4] = {0};
        int max, min;
        for(int i = 0; i < 4; i++){
            a[i] = n % 10;
            n /= 10;
        }
        sort(a, a + 4);
        max = a[3] * 1000 + a[2] * 100 + a[1] * 10 + a[0];
        min = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
        printf("%04d - %04d = %04d\n",max, min, max - min);
        n = max - min;
        if(n == 6174)
            break;
    }
    return 0;
}
