#include<bits/stdc++.h>
using namespace std;
constexpr int N = 5e5+5;
int n,k,a[N];

int main(){
    cin>>n>>k;
    for (int i=1;i<=n;i++)scanf("%d",a+i);
    int l=1,r=n;
    while (r!=l){
        unordered_set<int> ust;
        for (int i=l;i<r;i++)ust.insert(a[i]);
        int cnt=ust.size();
        if (cnt>k)l++,r--;
        else r++;
        if (cnt<=k)break;
    }
    cout<<l<<"  "<<r-1<<endl;


    return 0;
}