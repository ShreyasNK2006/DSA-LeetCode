/*
 * Problem 4041: Minimum Operations to Form Subset Sum II
 * URL     : https://leetcode.com/problems/minimum-operations-to-form-subset-sum-ii/
 * Solved  : 2026-08-30
 * Runtime : 739 ms
 * Memory  : 98.4 MB
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
            unordered_set<int> op2=options;
            for(auto it:options)
            {
                curr = it;
                steps=0;
                if(make_sum[it]!=INT_MAX)
                steps=make_sum[it];
                while(curr<=sum)
                {
                    op2.insert(curr);
                    make_sum[curr]=min(make_sum[curr],steps);
                    curr*=2;
                    steps++;
                }
            }
            vector<int> cp =dp;
            for(int j=0;j<=sum;j++)
            {
                if(dp[j]==INT_MAX)
                continue;
                for(auto it:op2)
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