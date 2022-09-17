#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,day=0;
    cin>>n>>m;
    while (n){
        n--,day++;
        if (day%m==0)n++;
    }
    cout<<day<<endl;
    return 0;
}