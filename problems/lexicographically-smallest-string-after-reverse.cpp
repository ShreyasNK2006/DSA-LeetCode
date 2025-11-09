# Lexicographically Smallest String After Reverse
Solved on 2025-10-25

class Solution {
public:
    void compare(string &res,string &temp)
    {
        for(int i=0;i<res.length();i++)
            {
                if(res[i]>temp[i])
                {
                    res=temp;
                    break;
                }
                else if(res[i]<temp[i])
                {
                    break;
                }
            }
    }
    string reversest(string s,int j)
    {
        for(int st=0;st<j/2;st++)
            {
                swap(s[st],s[j-st-1]);
            }
        return s;
    }
    string reverseend(string s,int j){
        for(int st=0;st<j/2;st++)
            {
                swap(s[st+s.length()-j],s[s.length()-1-st]);
            }
        return s;
    }
    string lexSmallest(string s) {
        string res=s,temp;
        for(int i=1;i<=s.length();i++)
            {
                temp =reversest(s,i);
                compare(res,temp);
                temp = reverseend(s,i);
                compare(res,temp);
            }
        return res;
    }
};