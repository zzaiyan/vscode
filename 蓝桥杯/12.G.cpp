#include<bits/stdc++.h>
using namespace std;
int n,g[10005];
unordered_set<int> us;
void dfs(int x,int sum){
    if (x>n){
        if (sum>0)us.insert(sum);
        return;
    }
    dfs(x+1,sum);
    dfs(x+1,sum+g[x]);
    dfs(x+1,sum-g[x]);
}
signed main(){
    cin>>n;
    for (int i=1;i<=n;++i)scanf("%d",g+i);
    dfs(1,0);
    cout<<us.size()<<endl;
    return 0;
}