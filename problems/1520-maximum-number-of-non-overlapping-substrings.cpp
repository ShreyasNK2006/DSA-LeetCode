/*
 * Problem 1520: Maximum Number of Non-Overlapping Substrings
 * URL     : https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/
 * Solved  : 2026-09-18
 * Runtime : 31 ms
 * Memory  : 29.7 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<pair<int,int>> occ(26,{-1,-1});
        int n = s.size();
        for(int i =0;i<n;i++)
        {
            if(occ[s[i]-'a'].first==-1)
            {
                occ[s[i]-'a']={i,i};
            }
            else
            {
                occ[s[i]-'a'].second=i;
            }
        }
        vector<pair<int,string>> temp;
        for(int i=0;i<26;i++)
        {
            string t;
            int st = occ[i].first,end = occ[i].second;
            if(st==-1)
            continue;
            bool valid = true;
            for(int j=st;j<=end;j++)
            {
                if(s[st]==s[j])
                t.push_back(s[j]);
                else
                {
                    if(occ[s[j]-'a'].first>=st)
                    {
                        end = max(end,occ[s[j]-'a'].second);
                        t.push_back(s[j]);
                    }
                    else
                    {
                        valid = false;
                        break;
                    }
                }
            }
            if(valid)
            temp.push_back({end-st+1,t});
        }
        sort(temp.begin(),temp.end());
        vector<string> res;
        unordered_set<char> st;
        for(int i=0;i<temp.size();i++)
        {
            bool skip = false;
            for(char c:temp[i].second)
            {
                if(st.find(c)!=st.end())
                {
                    skip = true;
                    break;
                }
            }
            if(skip)
            continue;
            res.push_back(temp[i].second);
            for(char c:temp[i].second)
            {
                st.insert(c);
            }
        }
        return res;
    }
};