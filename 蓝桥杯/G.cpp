#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while (T--){
        int cnt=0;
        long long num,i;
        cin >> num;
        unordered_map<int,int> ump;
        set<int> st;
        //ump[1]=2;
        for (i=2;i<=num;++i){
            while (num!=i)
                if (num%i==0){
                    ump[i]++;
                    num /= i;
                }
                else break;
        }
        ump[num]++;
        //for (auto i:ump)cout<<i.first<<' '<<i.second<<endl;
        for (auto i:ump){
            if (i.second<2){
                goto noFlag;
            }
            else st.insert(i.second);
        }
        if (0){
        yesFlag:
            cout<<"yes\n";
            continue;
        }
        if (0){
        noFlag:
            cout<<"no\n";
            continue;
        }
        int stSize=st.size();
        if (stSize<=2)cout<<"yes\n";
        else{
            vector<int> ele;
            for (auto t:st)
                ele.push_back(t);
            for (auto t:ele)
                if (t%ele[0]==0||t%ele[1]==0)--stSize;
            if (stSize<=2)cout<<"yes\n";
            else cout<<"no\n";
        }
    }
    return 0;
}