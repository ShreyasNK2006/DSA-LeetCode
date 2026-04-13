/*
 * Problem 3872: Longest Arithmetic Sequence After Changing At Most One Element
 * URL     : https://leetcode.com/problems/longest-arithmetic-sequence-after-changing-at-most-one-element/
 * Solved  : 2026-03-15
 * Runtime : 47 ms
 * Memory  : 227.1 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n=nums.size();
        vector<int> lft(n,2),rht(n,2);
        int diff=nums[1]-nums[0];
        for(int i=2;i<n;i++)
        {
            if(nums[i]-nums[i-1]==diff)
            lft[i]=lft[i-1]+1;
            else
            diff=nums[i]-nums[i-1];
        }
        diff=nums[n-1]-nums[n-2];
        for(int i=n-3;i>=0;i--)
        {
            if(nums[i+1]-nums[i]==diff)
            rht[i]=rht[i+1]+1;
            else
            diff=nums[i+1]-nums[i];
        }
        int maxlen=3;
        for(int i=0;i<n;i++)
        {
            maxlen=max(maxlen,max(lft[i],rht[i]));
            if(i==0)
            maxlen=max(maxlen,1+rht[i+1]);
            else if(i==n-1)
            maxlen=max(maxlen,1+lft[i-1]);
            else
            {
                maxlen=max(maxlen,1+lft[i]);
                maxlen=max(maxlen,1+rht[i]);
                if((nums[i+1]-nums[i-1])%2==0)
                {
                    int d=(nums[i+1]-nums[i-1])/2;
                    int left=1,right=1;
                    if(i>=2 && nums[i-1]-nums[i-2]==d)
                    left=lft[i-1];
                    if(i<=n-3 && nums[i+2]-nums[i+1]==d)
                    right=rht[i+1];
                    maxlen=max(maxlen,1+left+right);
                }
            }
        }
        return maxlen;
    }
};