/*
 * Problem 3876: Construct Uniform Parity Array II
 * URL     : https://leetcode.com/problems/construct-uniform-parity-array-ii/
 * Solved  : 2026-09-03
 * Runtime : 7 ms
 * Memory  : 165.8 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minn=INT_MAX,o=0;
        for(int i=0;i<nums1.size();i++)
            {
                if(nums1[i]%2!=0)
                    o++;
                minn=min(minn,nums1[i]);
            }
        if(o==0 || o==nums1.size() || minn%2!=0)
            return true;
        else 
            return false;
    }
};