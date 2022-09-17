#include<bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
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
    vector<int> vec;
    char t;
    while(t=getchar()!=EOF&&t!='a')vec.push_back(t-'0');

    cout<<lengthOfLIS(vec)<<endl;

}
