#include<bits/stdc++.h>
using namespace std;
int a[1005],n;
vector<int> ans;
int main(){
    cin>>n;
    for (int i=1;i<=n;i++)scanf("%d",a+i);
    for (int i=0;i<n;i++)a[i]=a[i+1]-a[i];
    for (int k=1;k<=n;k++){
        bool ret=1;
        for (int i=k;i<n;i++)
            if (a[i]!=a[i-k])ret=0;
        if (ret)ans.push_back(k);
    }
    cout<<ans.size()<<endl;
    for (auto i:ans)cout<<i<<' ';
    return 0;
}