#include<bits/stdc++.h>
using namespace std;
int main(){
    unsigned long long mt;
    cin>>mt;
    mt/=1000;
    int s=mt%60;
    int m=mt/(60)%60;
    int h=mt/(3600)%24;
    printf("%02d:%02d:%02d\n",h,m,s);
    return 0;
}