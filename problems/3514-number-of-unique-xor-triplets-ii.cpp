/*
 * Problem 3514: Number of Unique XOR Triplets II
 * URL     : https://leetcode.com/problems/number-of-unique-xor-triplets-ii/
 * Solved  : 2026-07-24
 * Runtime : 2287 ms
 * Memory  : 98.5 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> st,res;
        int n=nums.size();
        int l=-1,r=-1;
        st.insert(0);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int x=nums[i]^nums[j];
                st.insert(x);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(auto s:st)
            {
                int x=nums[i]^s;
                res.insert(x);
            }
        }
        return res.size();
    }
};