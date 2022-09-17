#include<bits/stdc++.h>
using namespace std;
int X,Y,M;
bool can[1005];
int main(){
    cin>>X>>Y>>M;
    int a=min(X,Y),b=max(X,Y);
    for (int i=0;i<=M;++i){
        if (i%a==0||i%b==0)
            can[i]=1;
        if (i>=b)can[i]=can[i-a]||can[i-b];
        else if (i>=a)can[i]=can[i-a];
    }
    for (;;M--)if (can[M])break;
    cout<<M;
    return 0;
}