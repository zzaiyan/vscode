#include<bits/stdc++.h>
using namespace std;
int arr[4],rmin=0x3f3f3f3f,rmax;
int main(){
    for(int i=1;i<=3;++i)cin>>arr[i];
    int gap1=arr[2]-arr[1],gap2=arr[3]-arr[2];
    int mingap=min(gap1,gap2),maxgap=max(gap1,gap2);
    if(gap1==1&&gap2==1)return !(cout<<"0\n0");
    if(mingap==1&&maxgap>1)rmin=min(rmin,2);
    if(mingap==2||maxgap==2)rmin=min(rmin,1);
    if(mingap>2)rmin=min(rmin,2);
    if(maxgap>2)rmax=max(rmax,maxgap-1);
    rmax=max(rmax,rmin);
    cout<<rmin<<'\n'<<rmax;
    return 0;
}