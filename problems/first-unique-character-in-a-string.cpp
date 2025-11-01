# First Unique Character in a String
Solved on 2025-10-14

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> inp;
        for(int i=0;i<s.length();i++)
        inp[s[i]]++;
        for(int i=0;i<s.length();i++)
        if(inp[s[i]]==1)
        return i;
        return -1;
    }
};