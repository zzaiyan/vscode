#include<bits/stdc++.h>
using namespace std;
int arr[100005],d[100005],dp[100005];
int n,k;
pair<int,int> LIS(){
    int maxL,last,now,gap=0;
    memset(dp,0,(n+1)*4);
    dp[0] = 1;
    for (int i = 1; i < n; i++){
        maxL = 1,last=0,gap=0;
        for (int j = 0; j < i; j++)
            if (arr[j] <= arr[i]){
                //maxL = max(maxL,dp[j] + 1);
                if (maxL<dp[j]+1){
                    now=j;
                    maxL=dp[j]+1;
                    gap=max(gap,now-last);
                    last=now;
                }
                
            }
        dp[i] = maxL;
    }
    return {*max_element(dp,dp+n),gap-1};
}
bool check(int x){
    int cnt=0;
    auto get=LIS();

    return x<=78534;
}
int main(){
    cin>>n>>k;
    for (int i=0;i<n;++i)scanf("%d",arr+i);
    // int l=0,r=n;
    // while (l<r){
    //     int mid=l+r+1>>1;
    //     if (check(mid))l=mid;
    //     else r=mid-1;
    // }
    // cout<<l<<endl;
    cout<<LIS().first<<endl;
    cout<<LIS().second<<endl;
    return 0;
}