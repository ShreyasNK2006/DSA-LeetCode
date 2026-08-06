/*
 * Problem 1081: Smallest Subsequence of Distinct Characters
 * URL     : https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
 * Solved  : 2026-07-19
 * Runtime : 3 ms
 * Memory  : 8.9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    string smallestSubsequence(string s) {
        string res;
        unordered_map<char,int> mp1,mp2;
        for(char c:s)
        {
            mp1[c]++;
            mp2[c]=0;
        }
        int n=mp1.size();
        stack<char> st;

        for(int i=0;i<s.size();i++)
        {
            mp1[s[i]]--;
            if(mp2[s[i]]==1)
            continue;
            while(!st.empty())
            {
                if(st.top()>s[i] && mp1[st.top()]>0)
                {
                    mp2[st.top()]=0;
                    st.pop();
                }
                else
                break;
            }
            st.push(s[i]);
            mp2[s[i]]=1;
        }
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};