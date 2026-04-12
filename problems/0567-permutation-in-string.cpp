/*
 * Problem 0567: Permutation in String
 * URL     : https://leetcode.com/problems/permutation-in-string/
 * Solved  : 2026-04-02
 * Runtime : 2 ms
 * Memory  : 10.1 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26,0);
        for(int i=0;i<s1.size();i++)
        freq[s1[i]-'a']++;
        if(s1.size()>s2.size())
        return false;
        vector<int> res(26,0);
        for(int i=0;i<min(s1.size(),s2.size())-1;i++)
        res[s2[i]-'a']++;
        for(int i=0;i<s2.size()-s1.size()+1;i++)
        {
            res[s2[s1.size()-1+i]-'a']++;
            bool cond=true;
            for(int j=0;j<26;j++)
            {
                if(res[j]!=freq[j])
                {
                    cond=false;
                    break;
                }
            }
            if(cond)
            return true;
            res[s2[i]-'a']--;
        }
        return false;
    }
};