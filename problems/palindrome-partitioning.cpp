# Palindrome Partitioning
Solved on 2025-10-04

class Solution {
public:
    void calcpermutations(vector<vector<string>>& res,string s,vector<string> temp,int ind)
    {
        if(ind==s.length())
        {
            if(!temp.empty())
            res.push_back(temp);
            return;
        }
        for(int i=ind;i<s.length();i++)
        {
            string subs = s.substr(ind,i-ind+1);
            if(palindrome(subs))
            {
            temp.push_back(subs);
            calcpermutations(res,s,temp,i+1);
            temp.pop_back();
            }
        }
    }
    bool palindrome(string s)
    {
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==s[s.length()-i-1])
            continue;
            else 
            return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
     vector<vector<string>> res;
     vector<string> temp;
     calcpermutations(res,s,temp,0);
     return res;   
    }
};