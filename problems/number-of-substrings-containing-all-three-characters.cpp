# Number of Substrings Containing All Three Characters
Solved on 2025-11-14

class Solution {
public:
    int numberOfSubstrings(string s) {
        int a=-1,b=-1,c=-1;
        int count=0,temp;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='a')
            a=i;
            else if(s[i]=='b')
            b=i;
            else if(s[i]=='c')
            c=i;
            if(a>-1 && b>-1 && c>-1)
            {
                temp=min(a,min(b,c));
                count+=(temp+1);
            }
        }
        return count;
    }
};