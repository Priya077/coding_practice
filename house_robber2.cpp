/*You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.*/

#include<bits/stdc++.h>

using namespace std;

int rob(vector<int>& nums) {
    int n=nums.size();
    if(n==1) return nums[0];
    int prev1=nums[0],prev2=0;
    for(int i=1;i<n;i++)
    {
       int take=nums[i]+prev2;
       int not_take=prev1;
       int curr=max(take,not_take);
       prev2=prev1;
       prev1=curr;
    }
    return prev1;
}

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
    if(N==1) return nums[0];
    vector<int>v1,v2;
    for(int i=0;i<N;i++)
    {

        if(i!=N-1) v1.push_back(nums[i]);
        if(i!=0) v2.push_back(nums[i]);
    }
    cout<<max(rob(v1),rob(v2));
    return 0;
}
