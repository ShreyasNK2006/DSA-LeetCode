/*
 * Problem 1658: Minimum Operations to Reduce X to Zero
 * URL     : https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
 * Solved  : 2026-09-23
 * Runtime : 225 ms
 * Memory  : 189 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<long long,int> suffix;
        int n= nums.size();
        long long sum=0;
        sum=0;
        suffix[0]=n;
        for(int i=n-1;i>=0;i--)
        {
            sum+=nums[i];
            suffix[sum]=i;
        }
        sum=0;
        int steps =INT_MAX;
        if(suffix.count(x)>0)
        steps = n-suffix[x];
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum<=x)
            {
                if(suffix.count(x-sum)>0)
                {
                    if(suffix[x-sum]<=i)
                    break;
                    steps = min(steps,i+1+n-suffix[x-sum]);
                }
            }
            else
            break;

        }
        return steps!=INT_MAX?steps:-1;
    }
};