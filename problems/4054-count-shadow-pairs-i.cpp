/*
 * Problem 4054: Count Shadow Pairs I
 * URL     : https://leetcode.com/problems/count-shadow-pairs-i/
 * Solved  : 2026-09-22
 * Runtime : 251 ms
 * Memory  : 302.3 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        stack<int> st;
        long long count=0;
        int n= nums.size();
        unordered_map<int,int> fq;
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                st.push(nums[i]);
                fq[nums[i]]++;
            }
            else
            {
                while(!st.empty() && st.top()>nums[i])
                {
                    fq[st.top()]--;
                    st.pop();
                }
                count += (st.size()-fq[nums[i]]);
                st.push(nums[i]);
                fq[nums[i]]++;
            }
        }
        return count;
    }
};