/*
 * Problem: Minimum Window Substring
 * Solved on: 2025-11-15
 * Runtime: 18 ms
 * Memory: 11.5 MB
*/

class Solution {
public:
    string minWindow(string s, string t) {
        int st=0,midlen=INT_MAX;
        int need = t.length();
        int counter=0;
        unordered_map<char,int> freqt;
        unordered_map<char,int> freqs;
        for(char c:t)
        {
            freqt[c]++;
        }
        int left=0,right=0;
        while(right<s.length())
        {
            if(freqt.find(s[right])!=freqt.end())
            {
                freqs[s[right]]++;
                if(freqs[s[right]]<=freqt[s[right]])
                counter++;
            }
            while(counter==need)
            {
                if(right-left+1<midlen)
                {
                    st=left;
                    midlen= right-left+1;
                }
                if(freqt.find(s[left])!=freqt.end())
                {
                    if(freqs[s[left]]<=freqt[s[left]])
                    counter--;
                    freqs[s[left]]--;
                }
                left++;
            }
            right++;
        }
        string res="";
        res=midlen==INT_MAX ?"":s.substr(st,midlen);
        return res;
    }
};