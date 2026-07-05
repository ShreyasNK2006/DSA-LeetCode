/*
 * Problem 3937: Minimum Operations to Make Array Modulo Alternating I
 * URL     : https://leetcode.com/problems/minimum-operations-to-make-array-modulo-alternating-i/
 * Solved  : 2026-05-28
 * Runtime : 179 ms
 * Memory  : 24 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int minop=INT_MAX;
        int n=nums.size();
        for(int i=0;i<k;i++)
            {
                for(int j=0;j<k;j++)
                    {
                        if(i==j)
                            continue;
                        int op=0;
                        for(int m=0;m<n;m++)
                        {
                            if(m%2==0)
                            op+=min(abs(i-nums[m]%k),k-abs(i-nums[m]%k));
                            else
                                op+=min(abs(j-nums[m]%k),k-abs(j-nums[m]%k));
                        }
                        minop=min(minop,op);
                    }
            }
        return minop;
    }
};