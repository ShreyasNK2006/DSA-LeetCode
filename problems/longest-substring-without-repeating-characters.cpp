# Longest Substring Without Repeating Characters
Solved on 2025-11-08

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
                mp.clear();
                i-=(int)temp.length();
                i++;
                temp.clear();
            }
        }
        len = max(len,(int)temp.length());
        return len;
    }
};