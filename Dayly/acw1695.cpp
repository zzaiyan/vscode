#include<bits/stdc++.h>
using namespace std;
int n,a,b,c;
int arr[]={0,1,2,3},mark[4];
int main(){
    cin>>n;
    while(n--){
        cin>>a>>b>>c;
        swap(arr[a],arr[b]);
        ++mark[arr[c]];
    }
    cout<<*max_element(mark+1,mark+4);
    return 0;
}