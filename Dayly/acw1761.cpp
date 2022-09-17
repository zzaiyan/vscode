#include<bits/stdc++.h>
using namespace std;
int grid[2005][2005];
int main(){
    int ax1,ay1,bx1,by1,cnt=0;
    int ax2,ay2,bx2,by2;
    int ax3,ay3,bx3,by3;
    cin>>ax1>>ay1>>bx1>>by1;
    cin>>ax2>>ay2>>bx2>>by2;
    cin>>ax3>>ay3>>bx3>>by3;
    ax1+=1000,ay1+=1000,bx1+=1000,by1+=1000;
    ax2+=1000,ay2+=1000,bx2+=1000,by2+=1000;
    ax3+=1000,ay3+=1000,bx3+=1000,by3+=1000;
    for(int i=0;i<=2000;++i)
        for(int j=0;j<=2000;++j){
            if(i>ax1&&i<=bx1&&j>ay1&&j<=by1)grid[i][j]=1;
            if(i>ax2&&i<=bx2&&j>ay2&&j<=by2)grid[i][j]=1;
            if(i>ax3&&i<=bx3&&j>ay3&&j<=by3)grid[i][j]=0;
        }
    for(int i=0;i<=2000;++i)
        for(int j=0;j<=2000;++j)
            cnt+=grid[i][j];
    return !(cout<<cnt);
}