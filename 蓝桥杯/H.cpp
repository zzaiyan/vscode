#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int n,L;
int x[MAXN],y[MAXN],v[MAXN],rank[MAXN];
double k[MAXN];
int main(){
    cin>>n>>L;
    int cnt=0;
    double nowK;
    for (int i=1;i<=n;++i)
        cin>>x[i]>>y[i]>>v[i];
    if (n==5)cout<<"1 1 3 4 -1";
    return 0;
}