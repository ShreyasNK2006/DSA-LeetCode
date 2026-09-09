/*
 * Problem 3720: Lexicographically Smallest Permutation Greater Than Target
 * URL     : https://leetcode.com/problems/lexicographically-smallest-permutation-greater-than-target/
 * Solved  : 2026-08-27
 * Runtime : 4 ms
 * Memory  : 10.7 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        map<char,int> mp,cp;
        for(auto c:s)
        mp[c]++;
        cp=mp;
        string res;
        bool greater=false;
        int n=target.size();
        int i=0;
        int first=-1;
        char u='0';
        for(;i<n;i++)
        {
            auto it= cp.lower_bound(target[i]);
            auto it2 = cp.upper_bound(target[i]);
            if(it2!=cp.end())
            {
                first=i;
                u=it2->first;
            }
            if(it==cp.end())
            break;
            if(it->first!=target[i])
            break;
            cp[it->first]--;
            if(cp[it->first]==0)
            cp.erase(it->first);
        }
        //cout<<u;
        if(first==-1)
        return "";
        for(int j=0;j<first;j++)
        {
            res.push_back(target[j]);
            mp[target[j]]--;
            if(mp[target[j]]==0)
            mp.erase(target[j]);
        }
        if(u!='0')
        {
            res.push_back(u);
            mp[u]--;
            if(mp[u]==0)
            mp.erase(u);
        }
        for(auto it:mp)
        {
            while(mp[it.first]>0)
            {
                res.push_back(it.first);
                mp[it.first]--;
            }
        }
        return res;
    }
};