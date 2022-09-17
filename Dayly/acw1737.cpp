#include<bits/stdc++.h>
using namespace std;
int a,b,x,y;
int main(){
    cin>>a>>b>>x>>y;
    int s1=abs(a-b);
    int s2=abs(a-x)+abs(b-y);
    int s3=abs(a-y)+abs(b-x);
    cout<<min(min(s1,s2),s3);
    return 0;
}