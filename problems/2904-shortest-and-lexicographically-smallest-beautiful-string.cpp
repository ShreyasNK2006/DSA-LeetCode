/*
 * Problem 2904: Shortest and Lexicographically Smallest Beautiful String
 * URL     : https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/
 * Solved  : 2026-08-26
 * Runtime : 0 ms
 * Memory  : 9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    string conv(deque<char> dq)
    {
        string t;
        while(!dq.empty())
        {
            t.push_back(dq.front());
            dq.pop_front();
        }
        return t;
    }
    string shortestBeautifulSubstring(string s, int k) {
        unordered_map<int,string> mp;
        int n=s.size();
        int f=0;
        int minlen = n+1;
        int len=0;
        string temp;
        for(int i=0;i<n;i++)
        {
            if(f==k)
            {
                //string t = conv(temp);
                if(len == minlen)
                {
                    mp[len]=min(temp,mp[minlen]);
                }
                else if(len<minlen)
                {
                    minlen =len;
                    mp[len]=temp;
                }
                int j=i-len+1;
                f--;
                len--;
                temp.erase(0,1);
                while(j< n && s[j]=='0')
                {
                    j++;
                    len--;
                    temp.erase(0,1);
                }
            }
            if(s[i]=='0' && f==0)
            continue;
            else if(s[i]=='1')
            {
                f++;
            }
            if(f!=0)
            {
                len++;
                temp.push_back(s[i]);
            }
        }
        if(f==k)
            {
                if(len == minlen)
                {
                    mp[len]=min(temp,mp[minlen]);
                }
                else if(len<minlen)
                {
                    minlen =len;
                    mp[len]=temp;
                }
            }
        if(mp.count(minlen)>0)
        return mp[minlen];
        else
        return "";
    }
};