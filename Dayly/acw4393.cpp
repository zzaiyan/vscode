#include<bits/stdc++.h>
using namespace std;
string str;
int ans,val[4];
int main(){
    for (int i=0;i<4;i++)cin>>val[i];
    cin>>str;
    for (auto i:str)
        ans+=val[i-'1'];
    cout<<ans<<endl;
    return 0;
}