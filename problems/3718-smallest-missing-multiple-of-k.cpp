/*
 * Problem 3718: Smallest Missing Multiple of K
 * URL     : https://leetcode.com/problems/smallest-missing-multiple-of-k/
 * Solved  : 2026-05-14
 * Runtime : 5 ms
 * Memory  : 25.1 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;
        int maxn=INT_MIN;
        for(int i=0;i<nums.size();i++)
            {
                st.insert(nums[i]);
                maxn=max(maxn,nums[i]);
            }
        int i=k;
        for(i=k;i<=maxn;i+=k)
            {
                if(st.find(i)==st.end())
                    return i;
            }
        return i;
    }
};