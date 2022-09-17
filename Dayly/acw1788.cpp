#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> ump;
int n,yes[11],ans;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        int cow,pos;
        cin>>cow>>pos;
        if (ump[cow]==0)ump[cow]=pos+1;
        else if (ump[cow]!=pos+1)
            ++yes[cow],ump[cow]=pos+1;
    }
    for (int i=1;i<=10;++i)ans+=yes[i];
    cout<<ans<<endl;
    return 0;
}