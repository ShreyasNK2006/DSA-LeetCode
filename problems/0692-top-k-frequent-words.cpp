/*
 * Problem 0692: Top K Frequent Words
 * URL     : https://leetcode.com/problems/top-k-frequent-words/
 * Solved  : 2026-04-02
 * Runtime : 0 ms
 * Memory  : 17.4 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(int i=0;i<words.size();i++)
        {
            mp[words[i]]++;
        }
        map<int,vector<string>> mp2;
        unordered_set<string>st;
        for(int i=0;i<words.size();i++)
        {
            if(st.find(words[i])==st.end())
            mp2[mp[words[i]]].push_back(words[i]);
            st.insert(words[i]);
        }
        vector<string> res;
        for(auto it=mp2.rbegin();it!=mp2.rend();++it)
        {
            vector<string> temp = it->second;
            sort(temp.begin(),temp.end());
            int s=temp.size();
            int j=0;
            while(k>0 && j<s)
            {
                res.push_back(temp[j]);
                k--;
                j++;
            }
            if(k==0)
            break;
        }
        return res;
    }
};