/*You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.*/


#include<bits/stdc++.h>

using namespace std;

int rob(vector<int>& nums) {
    int n=nums.size();
    if(n==1) return nums[0];
    //else if(n==2) return max(nums[0],nums[1]);
    int dp[n];
    dp[0]=nums[0],dp[1]=max(nums[0],nums[1]);
    for(int i=2;i<n;i++)
    {
        dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
    }
    return dp[n-1];
}
//more space optimized method in house robber 2
int main()
{

    int N,x;
    cin>>N;
    vector<int>nums;
    for(int i=0;i<N;i++)
    {

        cin>>x;
        nums.push_back(x);
    }
    cout<<rob(nums);
    return 0;
}
