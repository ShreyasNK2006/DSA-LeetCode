# Find the Difference
Solved on 2025-10-16

class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int i=0;
        while(i<s.length())
            {
                if(s[i]!=t[i])
                    return t[i];
                i++;
            }
        return t[i];
    }
};