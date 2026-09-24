/*
 * Problem 4040: Minimum Operations to Form Subset Sum I
 * URL     : https://leetcode.com/problems/minimum-operations-to-form-subset-sum-i/
 * Solved  : 2026-08-30
 * Runtime : 269 ms
 * Memory  : 100.4 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        int n = nums.size();
        vector<int> dp(sum+1,INT_MAX);
        dp[0]=0;
        for(int i=0;i<n;i++)
        {
            unordered_set<int> options;
            vector<int> make_sum(sum+1,INT_MAX);
            int curr = nums[i];
            int steps =0;
            while(curr<=sum)
            {
                options.insert(curr);
                make_sum[curr]=min(make_sum[curr],steps);
                curr*=2;
                steps++;
            }
            curr=nums[i];
            steps=0;
            while(curr>0)
            {
                if(curr<=sum)
                {
                    options.insert(curr);
                    make_sum[curr]=min(make_sum[curr],steps);
                }
                curr/=2;
                steps++;
            }
            vector<int> cp =dp;
            for(int j=0;j<=sum;j++)
            {
                if(dp[j]==INT_MAX)
                continue;
                for(auto it:options)
                {
                    if(j+it>sum)
                    continue;
                    if(make_sum[it]==INT_MAX)
                    continue;
                    cp[it+j]=min(cp[it+j],dp[j]+make_sum[it]);
                }
            }
            dp=cp;
        }
        if(dp[sum]==INT_MAX)
        return -1;
        return dp[sum];
    }
};