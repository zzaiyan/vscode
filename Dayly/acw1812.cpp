#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;

int main(){
    int tx,ty,T=4;
    int minX=INF,minY=INF,maxX=-INF,maxY=-INF;
    while (T--){
        cin>>tx>>ty;
        minX=min(minX,tx);
        minY=min(minY,ty);
        maxX=max(maxX,tx);
        maxY=max(maxY,ty);
    }
    
    int len=max((maxX-minX),(maxY-minY));
    cout<<len*len<<endl;

    return 0;
}