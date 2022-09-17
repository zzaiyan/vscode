#include<bits/stdc++.h>
using namespace std;
unordered_set<char> ust;
int main(){
    string str;
    while (cin>>str)
        for (char ch:str)
            if (ch>='a'&&ch<='z')
                ust.insert(ch);
    cout<<ust.size()<<endl;
    return 0;
}