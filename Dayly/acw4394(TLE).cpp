//二分搜索复杂度O(n2logn)
//Time Limit Exceeded

#include<bits/stdc++.h>
using namespace std;
constexpr int N = 5e5+5;
int n,k,a[N];

bool check(int x){
    int cnt=0x3f3f3f3f;
    for (int i=1;i+x-1<=n;i++){
        unordered_set<int> ust;
        for (int j=0;j<x;j++)
            ust.insert(a[i+j]);
        cnt=min(cnt,(int)ust.size());
    }
    return cnt<=k;
}

int main(){
    cin>>n>>k;
    for (int i=1;i<=n;i++)scanf("%d",a+i);
    int l=0,r=n;
    //for (int i=0;i<=n;i++)cout<<"i="<<i<<" check="<<check(i)<<endl;
    while (l<r){
        int mid=l+r+1>>1;
        if (check(mid))l=mid;
        else r=mid-1;
    }
    int len=l,cnt=0x3f3f3f3f;
    for (int i=1;i+len-1<=n;i++){
        unordered_set<int> ust;
        for (int j=0;j<len;j++)
            ust.insert(a[i+j]);
        cnt=min(cnt,(int)ust.size());
        if (cnt<=k){
            cout<<i<<' '<<i+len-1<<endl;
            break;
        }
    }
    return 0;
}