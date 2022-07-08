//Problem: https://leetcode.com/problems/find-pivot-index/

// optimal approach  T.C: O(n) ,S.C: O(1)

int pivotIndex(vector<int>& nums) {
        int rightSum = accumulate(nums.begin(),nums.end(),0);
        int leftSum = 0;
        for(int i=0;i<nums.size();i++){            
            rightSum -= nums[i];
            if(leftSum == rightSum){
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
 }

// my naive approach : T.C: O(n) ,S.C: O(2n)

/* int pivotIndex(vector<int>& nums) {
    int n=nums.size();
    int leftSum[n],rightSum[n];
    leftSum[0]=0,rightSum[n-1]=0;
    int sum=nums[0];
    for(int i=1;i<n;i++)
    {
        leftSum[i]=sum;
        sum+=nums[i];
    }
    sum=nums[n-1];
    for(int i=n-2;i>=0;i--)
    {
        rightSum[i]=sum;
        sum+=nums[i];
    }
    for(int i=0;i<n;i++)
    {
        if(leftSum[i]==rightSum[i]) return i;
    }
    return -1;
  } */