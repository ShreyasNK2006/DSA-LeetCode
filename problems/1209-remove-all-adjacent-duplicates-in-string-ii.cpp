/*
 * Problem 1209: Remove All Adjacent Duplicates in String II
 * URL     : https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
 * Solved  : 2026-07-24
 * Runtime : 17 ms
 * Memory  : 14 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>  st;
        for(char c:s)
        {
            if(!st.empty())
            {
                char x=st.top().first;
                int f=st.top().second;
                if(c==x)
                {
                    if(f+1==k)
                    st.pop();
                    else
                    {
                        st.pop();
                        st.push({c,f+1});
                    }
                }
                else
                {
                    st.push({c,1});
                }
            }
            else
            {
                st.push({c,1});
            }
        }
        string res;
        while(!st.empty())
        {
            char c=st.top().first;
            int x=st.top().second;
            while(x--)
            res+=c;
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};