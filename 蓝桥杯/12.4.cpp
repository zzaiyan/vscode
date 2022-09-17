#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans;
const int n = 24;
//const int n = 2021041820210418;
signed main(){
    for (int x=1;x<=n;++x){
        auto now=n;
        if (now%x!=0)continue;
        now/=x;
        for (int y=1;y<=n;++y){
            if (now%y!=0)continue;
            now/=y;
            for (int z=1;z<=n;++z){
                if (now%z!=0)continue;
                if (now/z==1)ans++;
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}