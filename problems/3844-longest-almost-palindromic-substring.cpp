/*
 * Problem 3844: Longest Almost-Palindromic Substring
 * URL     : https://leetcode.com/problems/longest-almost-palindromic-substring/
 * Solved  : 2026-05-16
 * Runtime : 39 ms
 * Memory  : 10.4 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int almostPalindromic(string s) {
        int maxlen=2;
        int n=s.size();
        bool extended=false;
        for(int i=0;i<n;i++)
        {
            int l=i,r=i;
            int len=0;
            while(l>=0 && r<n)
            {
                if(s[l]==s[r])
                {
                    len=r-l+1;
                    l--;
                    r++;
                }
                else if(l>0 && s[l-1]==s[r] && !extended)
                {
                    l--;
                    len=r-l+1;
                    l--;
                    r++;
                    extended=true;
                }
                else if(r<n-1 && s[l]==s[r+1] && !extended)
                {
                    r++;
                    len=r-l+1;
                    l--;
                    r++;
                    extended=true;
                }
                else break;
            }
            maxlen=max(maxlen,len);
            if(!extended && len<n)
            maxlen=max(maxlen,len+1);
            l=i,r=i+1;
            extended=false;
            len=0;
            while(l>=0 && r<n)
            {
                if(s[l]==s[r])
                {
                    len=r-l+1;
                    l--;
                    r++;
                }
                else if(l>0 && s[l-1] ==s[r] && !extended)
                {
                    l--;
                    len=r-l+1;
                    r++;
                    l--;
                    extended=true;
                }
                else if(r<n-1 && s[l]==s[r+1] && !extended)
                {
                    r++;
                    len=r-l+1;
                    r++;
                    l--;
                    extended=true;
                }
                else break;
            }
            maxlen=max(maxlen,len);
            if(!extended && len<n)
            maxlen=max(maxlen,len+1);
            extended=false;
        }
        for(int i=0;i<n;i++)
        {
            int l=i,r=i;
            int len=0;
            while(l>=0 && r<n)
            {
                if(s[l]==s[r])
                {
                    len=r-l+1;
                    l--;
                    r++;
                }
                else if(r<n-1 && s[l]==s[r+1] && !extended)
                {
                    r++;
                    len=r-l+1;
                    l--;
                    r++;
                    extended=true;
                }
                else if(l>0 && s[l-1]==s[r] && !extended)
                {
                    l--;
                    len=r-l+1;
                    l--;
                    r++;
                    extended=true;
                }
                else break;
            }
            maxlen=max(maxlen,len);
            if(!extended && len<n)
            maxlen=max(maxlen,len+1);
            l=i,r=i+1;
            extended=false;
            len=0;
            while(l>=0 && r<n)
            {
                if(s[l]==s[r])
                {
                    len=r-l+1;
                    l--;
                    r++;
                }
                else if(r<n-1 && s[l]==s[r+1] && !extended)
                {
                    r++;
                    len=r-l+1;
                    r++;
                    l--;
                    extended=true;
                }
                else if(l>0 && s[l-1] ==s[r] && !extended)
                {
                    l--;
                    len=r-l+1;
                    r++;
                    l--;
                    extended=true;
                }
                else break;
            }
            maxlen=max(maxlen,len);
            if(!extended && len<n)
            maxlen=max(maxlen,len+1);
            extended=false;
        }
        return maxlen;
    }
};