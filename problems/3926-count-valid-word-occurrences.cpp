/*
 * Problem 3926: Count Valid Word Occurrences
 * URL     : https://leetcode.com/problems/count-valid-word-occurrences/
 * Solved  : 2026-05-10
 * Runtime : 1087 ms
 * Memory  : 232.7 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s="";
        int m=chunks.size();
        for(int i=0;i<m;i++)
            s+=chunks[i];
        int n=s.size();
        cout<<s;
        unordered_map<string,int> mp;
        int st=0;
        string temp;
        for(int i=0;i<n;i++)
            {
                if(s[i]=='-' && (i==0 || s[i-1]==' '||s[i-1]=='-'))
                    continue;
                if((s[i]=='-' &&(i<n-1 && (s[i+1]=='-' || s[i+1]==' ')||i==n-1)))
                {
                    mp[temp]++;
                    cout<<temp<<endl;
                    st=i+2;
                    i++;
                    temp="";
                }
                else if((s[i]>='a' && s[i]<='z') ||s[i]=='-')
                {
                    temp.push_back(s[i]);
                }
                else
                {
                    cout<<temp<<endl;
                    mp[temp]++;
                    st=i+1;
                    temp="";
                }
            }
        mp[temp]++;
        int q=queries.size();
        vector<int> res(q,0);
        for(int i=0;i<q;i++)
            res[i]=mp[queries[i]];
        return res;
    }
};