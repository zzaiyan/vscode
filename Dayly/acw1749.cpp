#include<bits/stdc++.h>
using namespace std;
bool grid[2005][2005];
int main(){
    int ax1,ay1,ax2,ay2,bx1,by1,bx2,by2;
    cin>>ax1>>ay1>>ax2>>ay2>>bx1>>by1>>bx2>>by2;
    ax1+=1000,ay1+=1000,ax2+=1000,ay2+=1000,
    bx1+=1000,by1+=1000,bx2+=1000,by2+=1000;
    for(int i=0;i<=2000;++i)
        for(int j=0;j<=2000;++j){
            if(i>ax1&&i<=ax2&&j>ay1&&j<=ay2)grid[i][j]=true;
            if(i>bx1&&i<=bx2&&j>by1&&j<=by2)grid[i][j]=false;
        }
    int minx(0x3f3f3f3f),miny(0x3f3f3f3f),maxx(-0x3f3f3f3f),maxy(-0x3f3f3f3f);
    for(int i=0;i<=2000;++i)
        for(int j=0;j<=2000;++j)
            if(grid[i][j]){
                minx=min(minx,i),miny=min(miny,j),
                maxx=max(maxx,i),maxy=max(maxy,j);
            }
    if(maxx<minx||maxy<miny)return !(cout<<0);
    return !(cout<<((maxx-minx+1)*(maxy-miny+1)));
}