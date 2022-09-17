#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n,k,sum;

struct Card{
    int a,b,c;
}card[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //读入
    cin>>n>>k;
    for (int i=1;i<=n;i++)cin>>card[i].a;
    for (int i=1;i<=n;i++)cin>>card[i].b;
    //排序
    for (int i=1;i<=n;i++)card[i].c=card[i].a-card[i].b;
    sort(card+1,card+1+n,[](Card &A,Card &B){return A.c<B.c;});
    //判断
    if (k>=1&&card[k].c>=0){
        int i=1;
        for (;i<=k;i++)sum+=card[i].a;
        for (;i<=n;i++)sum+=card[i].b;
    }
    else{
        int i=1;
        for (;i<=n&&card[i].c<=0;i++)sum+=card[i].a;
        for (;i<=n;i++)sum+=card[i].b;
    }
    cout<<sum<<endl;
    return 0;
}