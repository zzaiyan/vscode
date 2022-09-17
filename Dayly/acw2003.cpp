#include<bits/stdc++.h>
using namespace std;

int solve(string &str){
    int ans = 0,cnt = 0;
    int len = str.size();
    for (int i=0; i+1<len; i++)
        if (str[i]=='('&&str[i+1]=='(')
            cnt++;
        else if (str[i]==')'&&str[i+1]==')')
            ans+=cnt;

    return ans;
}

int main(){
    string str;
    cin>>str;
    cout<<solve(str)<<"\n";
    return 0;
}