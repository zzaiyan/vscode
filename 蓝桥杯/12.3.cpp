#include<bits/stdc++.h>
using namespace std;
const int m=20,n=21;
unordered_set<double> us[m][n];
int main(){
    int ans=0;
    for (int x=0;x<m;++x)
        for (int y=0;y<n;++y){
            for (int i=0;i<m;++i)
                if (i!=x)for (int j=0;j<n;++j)
                    if (j!=y){
                        double k=1.0*(x-i)/(y-j);
                        us[x][y].insert(k);
                    }
            ans+=us[x][y].size();
        }
    ans/=2;
    ans+=m+n;
    cout<<ans<<endl;
    return 0;
}