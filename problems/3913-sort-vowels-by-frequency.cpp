/*
 * Problem 3913: Sort Vowels by Frequency
 * URL     : https://leetcode.com/problems/sort-vowels-by-frequency/
 * Solved  : 2026-05-06
 * Runtime : 634 ms
 * Memory  : 20.8 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    string sortVowels(string s) {
        unordered_set<char> st;
        st.insert({'a','e','i','o','u'});
        unordered_map<char,int> mp;
        for(auto c:s)
            {
                if(st.find(c)!=st.end())
                    mp[c]++;
            }
        stack<char> st2,st3,st4;
        for(auto it=mp.begin();it!=mp.end();it++)
            {
                st4.push(it->first);
            }
        while(!st4.empty())
            {
                auto it=st4.top();
                st4.pop();
                cout<<it<<endl;
                if(!st2.empty()) 
                {
                    while(!st2.empty() && mp[st2.top()]>=mp[it])
                    {
                        char temp =st2.top();;
                        st3.push(temp);
                        st2.pop();
                    }
                        st2.push(it);
                    while(!st3.empty())
                        {
                            char temp =st3.top();
                            st2.push(temp);
                            st3.pop();
                        }
                }
                else
                    st2.push(it);
            }
        for(int i=0;i<s.size();i++)
            {
                if(st.find(s[i])!=st.end())
                {
                    if(!st2.empty() && mp[st2.top()]>0)
                    {
                        s[i]=st2.top();
                        cout<<s[i]<<endl;
                        mp[st2.top()]--;
                        if(mp[st2.top()]==0)
                            st2.pop();
                    }
                }
            }
        return s;
    }
};