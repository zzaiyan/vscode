#include<bits/stdc++.h>
using namespace std;
int N,d[100005];//差分数组
vector<int> vec;
bool check(int x){
    int D=x-1,gap=0;
    vector<int> iv;
    memset(d,0,sizeof(int)*N);
    for(int num:vec){
        if(num<=D)d[0]++,d[num+D+1]--;
        else d[num-D]++,d[num+D+1]--;
    }
    int sum=d[0];
    for(int i=1;i<=N;++i){
        sum+=d[i];
        if(sum==0)iv.push_back(i);
    }
    //for(auto i:iv)cout<<i<<endl;
    int M=0,m=0x3f3f3f3f;
    if(iv.size()>=2){
	    for(auto i:iv)M=max(M,i),m=min(m,i);
	    gap=M-m;
    }
    //cout<<"x="<<x<<" gap="<<gap<<endl;
    return gap>=x;
}
void get(){
    string str;
    cin>>N>>str;
    int n=str.size();
    for(int i=0;i<n;++i)
        if(str[i]=='1')vec.push_back(i+1);
    //for(auto i:vec)cout<<i<<endl;
}
int main(){
    get();
    int gap=N;//原本的D
    int len=vec.size();
    for(int i=1;i<len;++i)gap=min(gap,vec[i]-vec[i-1]);
    //二分查找
    int l=0,r=gap;
    while(l<r){
        int mid=l+r+1>>1;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    cout<<l;
    return 0;
}