/*
 * Problem 3731: Find Missing Elements
 * URL     : https://leetcode.com/problems/find-missing-elements/
 * Solved  : 2026-05-16
 * Runtime : 9 ms
 * Memory  : 33.6 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minn=INT_MAX,maxn=INT_MIN;
        unordered_set<int> st;
        for(int x:nums)
            {
                minn=min(minn,x);
                maxn=max(maxn,x);
                st.insert(x);
            }
        vector<int> res={};
        for(int i=minn;i<=maxn;i++)
            {
                if(st.find(i)==st.end())
                    res.push_back(i);
            }
        return res;
    }
};