#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[10005];
bool check(int x){
    for (int i=1;i+x-1<=n;i++)
        if (a[i+x-1]-a[i]<=k)return 1;
    return 0;
}
int main(){
    cin>>n>>k;
    for (int i=1;i<=n;i++)scanf("%d",a+i);
    sort(a+1,a+1+n);
    //for (int i=1;i<=n;i++)cout<<"i="<<i<<" check="<<check(i)<<endl;
    int l=0,r=n;
    while(l<r){
        int mid=l+r+1>>1;
        if (check(mid))l=mid;
        else r=mid-1;
    }
    cout<<l<<endl;
    return 0;
}