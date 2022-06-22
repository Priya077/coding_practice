#include<bits/stdc++.h>

using namespace std;

int combinationSum4(vector<int>& nums, int target) {
      vector<unsigned int>dp(target+1,0); dp[0]=1;
      for(int i=0;i<=target;i++)
      {
        for(auto &it:nums)
        {
            if(it<=i) dp[i]+=dp[i-it];
        }
      }
      return dp[target];
}

int main()
{

    int N,x,target;
    cin>>N;
    vector<int>nums;
    for(int i=0;i<N;i++)
    {

        cin>>x;
        nums.push_back(x);
    }
    cin>>target;
    cout<<combinationSum4(nums,target);
    return 0;
}
