# Target Sum
Solved on 2025-11-12

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum =0;
        for(int num:nums)
        {
            sum+=num;
        }
        if((target+sum)%2!=0 || sum< abs(target))
        return 0;
        int p = (target+sum)/2;
       vector<int> dp(p+1,0);
       dp[0]=1;
       for(int num:nums)
       {
        for(int s = p;s>=num;s--)
        {
            dp[s]+= dp[s-num];
        }
       } 
       return dp[p];
    }
};