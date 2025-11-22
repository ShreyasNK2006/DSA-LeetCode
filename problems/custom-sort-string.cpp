/*
 * Problem: Custom Sort String
 * Solved on: 2025-11-16
 * Runtime: 0 ms
 * Memory: 8.5 MB
*/

class Solution {
public:
    string customSortString(string order, string s) {
       unordered_map<char,int> freqo;
       unordered_map<char,int> freqs;
       for(char c: order)
       {
        freqo[c]++;
       } 
       vector<char> a,b;
       for(char c :s)
       {
            freqs[c]++;
       }
       string res;
       for(char c: order)
       {
        while(freqo[c]<=freqs[c])
        {
            res.push_back(c);
            freqs[c]--;
        }
       }
       for(char c: s)
       {
        if(freqs[c])
        {
            res.push_back(c);
            freqs[c]--;
        }
       }
    return res;
    }
};