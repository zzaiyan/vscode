#include<bits/stdc++.h>
#define int long long
using namespace std;
int arr[11];
bool check(){
    for (int i=1;i<=10;++i)
        if (arr[i]<0)return false;
    return true;
}
signed main(){
    int cnt=1,t;
    for (int i=0;i<=10;++i)arr[i]=2021;
    while (1){
        t=cnt;
        while (t){
            arr[t%10]--;
            t/=10;
        }
        if (check())cout<<cnt++<<endl;
        else break;
    }
//	cout<<--cnt<<endl;
    return 0;
}