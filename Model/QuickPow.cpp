#include<bits/stdc++.h>
using namespace std;
#define int long long
//快速幂
int qpow(int a,int n,int M){
    if(n==0)return 1;
    else if(n&1)
        return qpow(a,n-1,M)*a%M;
    else{
        int temp=qpow(a,n/2,M)%M;
        return temp*temp%M;
    }
}

signed main(){
    int base,index;
    const int p=1e9+7;
    cin>>base>>index;
    cout<<qpow(base,index,p)<<endl;
    return 0;
}