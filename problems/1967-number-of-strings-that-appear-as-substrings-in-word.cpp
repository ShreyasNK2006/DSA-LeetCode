/*
 * Problem 1967: Number of Strings That Appear as Substrings in Word
 * URL     : https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/
 * Solved  : 2026-06-29
 * Runtime : 10 ms
 * Memory  : 12.9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int c=0;
        unordered_map<string,int> st;
        for(auto s:patterns)
        st[s]++;
        for(int i=0;i<word.size();i++)
        {
            string temp;
            for(int j=i;j<word.size();j++)
            {
                temp+=word[j];
                if(st.find(temp)!=st.end())
                {
                    c+=st[temp];
                    st[temp]=0;
                }
            }
        }
        return c;
    }
};