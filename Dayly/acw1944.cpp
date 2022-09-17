#include<bits/stdc++.h>
using namespace std;
int n,ans;
map<set<string>,int> mp;
int main(){
    cin>>n;
    while (n--){
        string a,b,c;
        cin>>a>>b>>c;
        set<string> ele={ a,b,c };
        mp[ele]++;
    }
    for (auto i:mp)ans=max(ans,i.second);
    cout<<ans<<endl;
    return 0;
}