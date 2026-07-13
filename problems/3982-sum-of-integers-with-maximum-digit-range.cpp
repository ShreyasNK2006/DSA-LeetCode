/*
 * Problem 3982: Sum of Integers with Maximum Digit Range
 * URL     : https://leetcode.com/problems/sum-of-integers-with-maximum-digit-range/
 * Solved  : 2026-07-05
 * Runtime : 0 ms
 * Memory  : 31.8 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        vector<vector<int>> diff(10);
        int maxdiff=0;
        for(auto x:nums)
            {
                int y=x;
                int maxn=0,minn=9;
                while(y)
                    {
                        int d=y%10;
                        y/=10;
                        maxn=max(maxn,d);
                        minn=min(minn,d);
                    }
                diff[maxn-minn].push_back(x);
                maxdiff=max(maxdiff,maxn-minn);
            }
        int sum=0;
        for(auto x:diff[maxdiff])
            sum=sum+x;
        return sum;
    }
};