#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int len1=max(b,d)-min(a,c);
    int len2=b-a+d-c;
    cout<<min(len1,len2);
    return 0;
}