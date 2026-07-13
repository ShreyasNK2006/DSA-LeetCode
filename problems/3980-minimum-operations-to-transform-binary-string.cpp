/*
 * Problem 3980: Minimum Operations to Transform Binary String
 * URL     : https://leetcode.com/problems/minimum-operations-to-transform-binary-string/
 * Solved  : 2026-07-04
 * Runtime : 11 ms
 * Memory  : 30.4 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int minOperations(string s1, string s2) {
        int n=s1.size();
        //vector<vector<int>> dp(n,vector<int> (2,INT_MAX));
        int c=0;
        for(int i=0;i<n;i++)
            {
                if(s1[i]==s2[i])
                    continue;
                else if(s1[i]=='0')
                    c++;
                else
                {
                    if(i==n-1)
                    {
                        if(i==0)
                            return -1;
                        else
                        {
                            c+=2;                          
                        }
                    }
                    else
                    {
                        if(s1[i+1]=='1' && s2[i+1]=='0')
                        {
                            s1[i+1]='0';
                            c++;
                        }
                        else if(s1[i+1]=='1' && s2[i+1]=='1')
                        {
                            c+=2;
                        }
                        else
                        {
                            c+=2;
                            if(s1[i+1]!=s2[i+1])
                                c++;
                            s1[i+1]=s2[i+1];
                        }
                    } 
                }
            }
        return c;
    }
};