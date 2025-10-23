# Majority Frequency Characters
Solved on 2025-09-27

class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<char,int> freq;
        for(char c:s)
            {
                freq[c]++;
            }
        map<int,int> freqg;
        int max =0,find=0;
        string res,res2;
        sort(s.begin(),s.end());
        res2+=s[0];
        int i=0;
        for(auto c:s)
            {
                if(res2[i]!=c)
                {
                    res2+=c;
                    i++;
                }
            }
        s=res2;
        for(char c:s)
            {
                freqg[freq[c]]++;
            }
        for(char c:s)
            {
                if(max<=freqg[freq[c]])
                {
                    if(max==freqg[freq[c]])
                        if(freq[c]<find)
                            continue;
                    max=freqg[freq[c]];
                    find=freq[c];
                }
            }
        int count=0;
        for(char c:s)
            {
                if(freq[c]==find)
                {
                    res+=c;
                    count++;
                }
            }
    return res;
    }
};