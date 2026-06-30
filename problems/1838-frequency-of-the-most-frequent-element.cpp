/*
 * Problem 1838: Frequency of the Most Frequent Element
 * URL     : https://leetcode.com/problems/frequency-of-the-most-frequent-element/
 * Solved  : 2026-04-30
 * Runtime : 1701 ms
 * Memory  : 122.7 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        map<int,int> freq;
        for(int n:nums)
        freq[n]++;
        int maxf=0;
        for(auto it=freq.rbegin();it!=freq.rend();it++)
        {
            auto it2=it;
            it2++;
            int k2=k;
            int f=it->second;
            while(k2>0 && it2!=freq.rend())
            {
                int diff=it->first-it2->first;
                if(diff>k2)
                break;
                if(k2/diff>=it2->second)
                {
                    f+=it2->second;
                    k2-=(diff*it2->second);
                }
                else if(k2/diff<it2->second)
                {
                    f+=(k2/diff);
                    k2-=(diff*(k2/diff));
                }
                it2++;
            }
            maxf=max(maxf,f);
        }
        return maxf;
    }
};