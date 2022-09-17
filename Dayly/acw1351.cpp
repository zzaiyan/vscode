#include<bits/stdc++.h>
using namespace std;
int n,key1[3],key2[3],ans;
set<int> st[2][3];
int main(){
    cin>>n;
    for (int i=0;i<3;i++)cin>>key1[i];
    for (int i=0;i<3;i++)cin>>key2[i];
    for (int j=0;j<3;j++){
        for (int i=-2;i<=2;i++){
            st[0][j].insert((key1[j]+i+10*n)%n);
            st[1][j].insert((key2[j]+i+10*n)%n);
        }
    }
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            for (int k=0;k<n;k++){
                if (st[0][0].count(i)&&st[0][1].count(j)&&st[0][2].count(k)){
                    ans++;
                    continue;
                }
                if (st[1][0].count(i)&&st[1][1].count(j)&&st[1][2].count(k))
                    ans++;
            }
    cout<<ans<<endl;
    return 0;
}