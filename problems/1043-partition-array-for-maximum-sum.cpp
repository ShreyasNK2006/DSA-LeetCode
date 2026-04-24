/*
 * Problem 1043: Partition Array for Maximum Sum
 * URL     : https://leetcode.com/problems/partition-array-for-maximum-sum/
 * Solved  : 2026-04-06
 * Runtime : 0 ms
 * Memory  : 12.5 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);
        dp[1]=arr[0];
        for(int i=1;i<n;i++)
        {
            int sum=0;
            int curr=0;
            for(int j=0;j<k;j++)
            {
                if(i-j<0)
                break;
                curr=max(curr,arr[i-j]);
                sum=max(sum,dp[i-j]+curr*(j+1));               
            }
            dp[i+1]=sum;
        }
        return dp[n];
    }
};