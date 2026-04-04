/*
 * Problem: Lexicographically Smallest Generated String
 * Solved on: 2026-03-31
 * Runtime: 19 ms
 * Memory: 10.7 MB
 * 
 * Explanation: (AI generation failed)
*/

class Solution {
public:
    string generateString(string str1, string str2) {
        int m=str2.size(),n=str1.size();
        string res(n+m-1,'?');
        for(int i=0;i<n;i++)
        {
            if(str1[i]=='T')
            {
                for(int j=0;j<m;j++)
                {
                    if(res[i+j]=='?'||res[i+j]==str2[j])
                    {
                        res[i+j]=str2[j];
                    }
                    else
                    return "";
                }
            }
        }
        for(int i=0;i<n+m-1;i++)
        {
            if(res[i]=='?')
            res[i]='a';
        }
        for(int i=0;i<n;i++)
        {
            if(str1[i]=='F')
            {
                bool same=true;
                for(int j=0;j<m;j++)
                {
                    if(res[i+j]!=str2[j])
                    {
                        same=false;
                        break;
                    }
                }
                if(same)
                {
                    bool changed=false;
                    for(int j=m-1;j>=0;j--)
                    {
                        char org=res[i+j];
                        for(char c='a';c<='z';c++)
                        {
                            if(c!=org)
                            {
                                res[i+j]=c;
                                bool ok=true;
                                for(int k=max(0,i+j-m+1);k<=min(i+j,n-1);k++)
                                {
                                    if(str1[k]=='T')
                                    {
                                        for(int t=0;t<m;t++)
                                        {
                                            if(res[t+k]!=str2[t])
                                            {
                                                ok=false;
                                                break;
                                            }
                                        }
                                        if(!ok)
                                        break;
                                    }
                                }
                                if(ok)
                                {
                                    changed=true;
                                    break;
                                }
                                res[i+j]=org;
                            }
                        }
                        if(changed)
                        break;
                    }
                    if(!changed)
                    return "";
                }
            }
        }
        return res;
    }
};