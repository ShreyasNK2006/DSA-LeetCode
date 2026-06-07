/*
 * Problem 3719: Longest Balanced Subarray I
 * URL     : https://leetcode.com/problems/longest-balanced-subarray-i/
 * Solved  : 2026-05-14
 * Runtime : 1980 ms
 * Memory  : 522.3 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size(),maxlen=0;
        for(int i=0;i<n;i++)
            {
                unordered_set<int> st;
                int oc=0,ec=0;
                for(int j=i;j<n;j++)
                    {
                        
                        if(st.find(nums[j])==st.end())
                        {
                            if(nums[j]%2==0)
                                ec++;
                            else
                                oc++;
                            st.insert(nums[j]);
                        }
                        if(oc==ec && oc!=0)
                            maxlen=max(maxlen,j-i+1);
                    }
            }
        return maxlen;
    }
};