#include<bits/stdc++.h>
using namespace std;
int A,B,N;
struct Flight{
    int fee;
    vector<int> via;
}flight[502];
vector<int> ans;
int search(int m,int x){
    int s=flight[m].via.size();
    for (int i=0;i<s;i++)
        if (flight[m].via[i]==x)return i;
    return -1;
}
int main(){
    cin>>A>>B>>N;
    for (int i=1;i<=N;i++){
        int temp,tnum;
        cin>>temp>>tnum;
        flight[i].fee=temp;
        for (int j=1;j<=tnum;j++){
            cin>>temp;
            flight[i].via.push_back(temp);
        }
    }
    for (int i=1;i<=N;i++){
        int a=search(i,A),b=search(i,B);
        if (a!=-1&&b!=-1&&a<b)ans.push_back(flight[i].fee);
    }
    if (ans.size())return !(cout<<*min_element(ans.begin(),ans.end()));
    else return !(cout<<-1);
}