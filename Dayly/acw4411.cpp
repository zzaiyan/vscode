#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    bool bow[3]{0};
    cin>>n>>x;
    bow[x]=1;
    //枚举可发现周期为6
    n%=6;
    while (n--){
        if ((n&1))swap(bow[1],bow[2]);
        else swap(bow[0],bow[1]);
        // for (int i=0;i<3;i++)
        //     if (bow[i])cout<<i<<endl;
    }
    for (int i=0;i<3;i++)
        if (bow[i])return !(cout<<i<<endl);
    return 0;
}