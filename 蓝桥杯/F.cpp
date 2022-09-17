#include<bits/stdc++.h>
using namespace std;
int n,nums[100005];
int lengthOfLIS(){
    vector<int> vec;
    vec.push_back(nums[0]);
    for(int i=1;i<n;i++){
        if(nums[i]>vec.back())
            vec.push_back(nums[i]);
        else
            *lower_bound(vec.begin(),vec.end(),nums[i])=nums[i];
    }
    return vec.size();
}
int main(){
    cin>>n;
    for (int i=0;i<n;++i)cin>>nums[i];
    cout<<lengthOfLIS()<<endl;


    return 0;
}