/*
 * Problem 3961: Maximize Sum of Device Ratings
 * URL     : https://leetcode.com/problems/maximize-sum-of-device-ratings/
 * Solved  : 2026-06-22
 * Runtime : 1 ms
 * Memory  : 156.7 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        long long sum=0;
        int minu=INT_MAX,minu2=INT_MAX;
        int m=units.size(),n=units[0].size();
        for(int i=0;i<m;i++)
        {
            int min1=INT_MAX,min2=INT_MAX;
            for(int j=0;j<n;j++)
            {
                if(min1>units[i][j])
                {
                    min2=min1;
                    min1=units[i][j];
                }
                else if(min2>units[i][j])
                {
                    min2=units[i][j];
                }
                minu=min(minu,min2);
                minu2=min(minu2,min1);
            }
            if(min2!=INT_MAX)
            sum=sum+1LL*min2;
            else
            sum=sum+1LL*min1;
        }
        if(minu!=INT_MAX)
        sum=sum-1LL*minu+1LL*minu2;
        return sum;
    }
};