#include<bits/stdc++.h>
using namespace std;
int main(){
    int x,y,ans=1,now=0,cow;
    cin>>x>>y;
    cow=abs(x-y);
    if (cow==0)return !(cout<<0);
    now=x<y?1:-1;
    if (cow==now)return !(cout<<1);
    while (1){
        ans+=3*abs(now);
        now*=-2;
        if (now>=cow)break;
    } 
    ans-=now-cow;
    cout<<ans;
    return 0;
}