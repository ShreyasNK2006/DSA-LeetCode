/*
 * Problem 0205: Isomorphic Strings
 * URL     : https://leetcode.com/problems/isomorphic-strings/
 * Solved  : 2026-05-01
 * Runtime : 0 ms
 * Memory  : 9.5 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;
        vector<int> marked(128,0);
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(mp.find(s[i])==mp.end())
            {
                if(marked[t[i]]==1)
                return false;
                mp[s[i]]=t[i];
                marked[t[i]]=1;
            }
            else
            {
                if(mp[s[i]]==t[i])
                continue;
                else
                return false;
            }
        }
        return true;
    }
};