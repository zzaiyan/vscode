#include<bits/stdc++.h>
using namespace std;
struct T{
    int c,m;
}t[3];
int main(){
    for(int i=0;i<3;++i)cin>>t[i].c>>t[i].m;
    for(int i=0;i<100;++i){
        int n1=i%3,n2=(i+1)%3;
        int d=min(t[n1].m,t[n2].c-t[n2].m);
        t[n1].m-=d,t[n2].m+=d;
    }
    printf("%d\n%d\n%d",t[0].m,t[1].m,t[2].m);
    return 0;
}