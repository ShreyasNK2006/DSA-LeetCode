/*
 * Problem 3921: Score Validator
 * URL     : https://leetcode.com/problems/score-validator/
 * Solved  : 2026-05-09
 * Runtime : 3 ms
 * Memory  : 54.8 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int s=0,c=0;
        int n=events.size();
        unordered_set<string> st={"0","1","2","3","4","6"};
        for(int i=0;i<n && c<10;i++)
            {
                if(st.find(events[i])!=st.end())
                    s+=(events[i][0]-'0');
                else if(events[i]=="W")
                    c++;
                else if(events[i]=="WD"||events[i]=="NB")
                    s++;
            }
        return {s,c};
    }
};