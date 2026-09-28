/*
 * Problem 1807: Evaluate the Bracket Pairs of a String
 * URL     : https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/
 * Solved  : 2026-09-26
 * Runtime : 106 ms
 * Memory  : 144.6 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;
        for(auto it:knowledge)
        {
            mp[it[0]]=it[1];
        }
        string res;
        bool open =false;
        string temp;
        for(char c:s)
        {
            if(c=='(')
            {
                open=true;
                continue;
            }
            else if(c==')')
            {
                open=false;
                if(mp.count(temp)>0)
                {
                    temp=mp[temp];
                    for(char x :temp)
                    {
                        res+=x;
                    }
                }
                else
                {
                    res+='?';
                }
                string ntemp;
                temp=ntemp;
                continue;
            }
            if(open)
            {
                temp+=c;
            }
            else
            res+=c;
        }
        return res;
    }
};