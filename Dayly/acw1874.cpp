#include<bits/stdc++.h>
using namespace std;
char grid[52][52];
int n,m;
unordered_set<int> ans;
int check(char M,char O){
    int cnt=0;
    for (int i=1;i<=n;i++)
        for (int j=2;j<=m-1;j++)
            if (grid[i][j]==O&&((grid[i][j-1]==M&&grid[i][j+1]==O)||(grid[i][j-1]==O&&grid[i][j+1]==M)))
                cnt++;

    for (int j=1;j<=m;j++)
        for (int i=2;i<=n-1;i++)
            if (grid[i][j]==O&&((grid[i-1][j]==M&&grid[i+1][j]==O)||(grid[i-1][j]==O&&grid[i+1][j]==M)))
                cnt++;

    for (int i=2;i<=n-1;i++)
        for (int j=2;j<=m-1;j++){
            if (grid[i][j]==O&&((grid[i-1][j-1]==M&&grid[i+1][j+1]==O)||(grid[i-1][j-1]==O&&grid[i+1][j+1]==M)))
                cnt++;
            if (grid[i][j]==O&&((grid[i-1][j+1]==M&&grid[i+1][j-1]==O)||(grid[i-1][j+1]==O&&grid[i+1][j-1]==M)))
                cnt++;
        }

    return cnt;
}
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            cin>>grid[i][j];
    for (int i=1;i<=500;i++)
        cout<<check('Q','M')<<endl;


    for (char i=0;i<=25;i++)
        for (char j=0;i<=25;j++)
            if (i!=j)ans.insert(check('A'+i,'A'+j));

    cout<<*max_element(ans.begin(),ans.end())<<endl;
    return 0;
}