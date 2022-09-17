#include<bits/stdc++.h>
using namespace std;
constexpr int N = 1e5+5;
int n,x[N],y[N],lSum[N],rSum[N];
int dis(int a,int b){
    return abs(x[a]-x[b])+abs(y[a]-y[b]);
}
int main(){
    cin>>n;
    for (int i=1;i<=n;i++)scanf("%d%d",x+i,y+i);
    for (int i=2;i<=n;i++)lSum[i]=lSum[i-1]+dis(i,i-1);
    for (int i=n-1;i>=1;i--)rSum[i]=rSum[i+1]+dis(i,i+1);
    int ans = 0x3f3f3f3f;
    for (int i=2;i<n;i++)
        ans=min(ans,lSum[i-1]+dis(i-1,i+1)+rSum[i+1]);
    cout<<ans<<endl;
    return 0;
}