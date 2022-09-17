#include<bits/stdc++.h>
#define elif else if
using namespace std;
int n,m;
char grid[1005][1005];
bool ray[1005][1005];
struct Pot{
    int x,y;
    void go(int d){
        if (d==2)y++;
        elif(d==4)x--;
        elif(d==6)x++;
        else y--;
    }
    bool legal(){
        if (x==0||y==0||x==n+1||y==m+1)
            return 0;
        else return 1;
    }
};
int getMax(int x,int y,int d){
    int cnt=0;
    memset(ray,0,sizeof(ray));
    Pot pot{ x,y };
    while (1){
        pot.go(d);
        if (pot.legal())ray[pot.x][pot.y]++,cnt++;
        else;
    }


}

int main(){
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            cin>>grid[i][j];


    return 0;
}