#include<bits/stdc++.h>
using namespace std;
string str,t,res;
int main(){
    cin>>str>>t;
    int ss=str.size(),ts=t.size();
    for (int i=0;i<ss;i++){
        res.push_back(str[i]);
        int rs=res.size();
        if (rs>=ts&&res.substr(rs-ts,ts)==t)
            res.erase(res.begin()+rs-ts,res.end());
    }
    cout<<res;
    return 0;
}