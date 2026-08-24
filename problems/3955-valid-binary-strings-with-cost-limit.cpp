/*
 * Problem 3955: Valid Binary Strings With Cost Limit
 * URL     : https://leetcode.com/problems/valid-binary-strings-with-cost-limit/
 * Solved  : 2026-06-07
 * Runtime : 59 ms
 * Memory  : 41.5 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    void findvalid(unordered_set<string> &st,int &n,int &k,vector<string> &res,int i,int cost,string prev)
    {
        if(st.find(prev)==st.end())
        res.push_back(prev);
        st.insert(prev);
        if(i==n)
            return;
        if((i>0 && prev[i-1]=='0')||(i==0 && prev[i]=='0'))
        {
            string cp=prev;
            cp[i]='1';
            if(cost+i<=k)
                findvalid(st,n,k,res,i+1,cost+i,cp);
        }
        findvalid(st,n,k,res,i+1,cost,prev);
    }
    vector<string> generateValidStrings(int n, int k) {
        vector<string> res;
        string temp;
        for(int i=0;i<n;i++)
            temp.push_back('0');
        //res.push_back(temp);
        unordered_set<string> st;
        findvalid(st,n,k,res,0,0,temp);//index,cost,prev
        return res;
    }
};