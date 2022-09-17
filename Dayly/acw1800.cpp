#include<bits/stdc++.h>
using namespace std;
int n,arr[10],cnt,ans=0x3f3f3f3f,ansCnt;
unordered_map<string,int> ump={{"Bessie",0},{"Elsie",0},{"Daisy",0},{"Gertie",0},{"Annabelle",0},{"Maggie",0},{"Henrietta",0}};
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        string name;
        int num;
        cin>>name>>num;
        ump[name]+=num;
    }
    for (auto i:ump)arr[cnt++]=i.second;
    int minEle=*min_element(arr,arr+7);
    for (auto i:ump)if (i.second>minEle)ans=min(ans,i.second);
    for (auto i:ump)if (i.second==ans)++ansCnt;
    if (ansCnt==1)for (auto i:ump)if (i.second==ans)return !(cout<<i.first);
    return !(cout<<"Tie");
}