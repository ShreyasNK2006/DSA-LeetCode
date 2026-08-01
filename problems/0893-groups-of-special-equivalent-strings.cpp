/*
 * Problem 0893: Groups of Special-Equivalent Strings
 * URL     : https://leetcode.com/problems/groups-of-special-equivalent-strings/
 * Solved  : 2026-07-02
 * Runtime : 6 ms
 * Memory  : 14.7 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        set<pair<string,string>> st;
        for(string s:words)
            {
                vector<int> even(26,0),odd(26,0);
                for(int i=0;i<s.size();i++)
                    {
                        if(i%2==0)
                            even[s[i]-'a']++;
                        else
                            odd[s[i]-'a']++;
                    }
                string odds,evens;
                for(int i=0;i<26;i++)
                    {
                        while(odd[i]--)
                            odds+=('a'+i);
                        while(even[i]--)
                            evens+=('a'+i);
                    }
                st.insert({odds,evens});
            }
        return (int)st.size();
    }
};