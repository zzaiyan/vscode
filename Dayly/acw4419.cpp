#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,ans=0;
    cin>>n;
    while (n--){
        int x,y;
        cin>>x>>y;
        if (y-x>=2)ans++;
    }
    cout<<ans<<endl;
    return 0;
}