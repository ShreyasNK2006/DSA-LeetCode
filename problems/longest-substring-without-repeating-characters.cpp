/*
 * Problem: Longest Substring Without Repeating Characters
 * Solved on: 2025-11-08
 * Runtime: 11 ms
 * Memory: 12.1 MB
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        string temp;
        int len=0;
        for(int i=0;i<s.length();i++)
        {
            temp.push_back(s[i]);
            mp[s[i]]++;
            if(mp[s[i]]==2)
            {
                len = max(len,(int)temp.length()-1);
                for(int j=0;j<temp.length();)
                {
                    mp[temp[j]]--;
                    if(temp[j]!=s[i])
                        temp.erase(temp.begin()+j);
                    else
                    {
                        temp.erase(temp.begin()+j);
                        break;
                    }
                }
            }
        }
        len = max(len,(int)temp.length());
        return len;
    }
};