#include<bits/stdc++.h>
using namespace std;
int N,h[1005],ans=0x3f3f3f3f,now;

int main(){
    cin>>N;
    for (int i=1;i<=N;i++)cin>>h[i];
    sort(h+1,h+1+N);
    for (int i=2;i<=N;i++)h[i]-=h[1];
    h[1]=0;
    if (h[N]<=17)ans=0;
    while (now+17<h[N]){
        int l,r,fee=0;
        for (l=1;h[l]<now;l++)
            fee+=(h[l]-now)*(h[l]-now);
        for (r=N;h[r]>now+17;r--)
            fee+=(h[r]-now-17)*(h[r]-now-17);
        ans=min(ans,fee);
        now++;
    }
    cout<<ans<<endl;
    return 0;
}