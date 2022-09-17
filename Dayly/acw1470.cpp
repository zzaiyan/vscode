#include<bits/stdc++.h>
using namespace std;
char grid[11][11];
int rx,ry,lx,ly,bx,by,ans;
int main(){
    for(int i=0;i<10;++i)
        cin>>grid[i];
    for(int i=0;i<10;++i)
        for(int j=0;j<10;++j)
            if(grid[i][j]=='L')lx=i,ly=j;
            else if(grid[i][j]=='R')rx=i,ry=j;
            else if(grid[i][j]=='B')bx=i,by=j;
    if((rx==lx&&rx==bx&&(ly-ry)*(ry-by)>0)||(ry==ly&&ry==by&&(lx-rx)*(rx-bx)>0))
        ans=abs(bx-lx)+abs(by-ly)+1;
    else ans=abs(bx-lx)+abs(by-ly)-1;
    return !(cout<<ans);
}