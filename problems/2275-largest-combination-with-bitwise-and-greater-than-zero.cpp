/*
 * Problem 2275: Largest Combination With Bitwise AND Greater Than Zero
 * URL     : https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/
 * Solved  : 2026-07-13
 * Runtime : 254 ms
 * Memory  : 186.9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxl=0;
        int n=candidates.size();
        vector<vector<int>> bits(n,vector<int>(32,0));
        for(int i=0;i<n;i++)
            {
                for(int j=0;j<32;j++)
                    {
                        int b= candidates[i]/(1<<(31-j));
                        if(b==1)
                        candidates[i]-=(1<<(31-j));
                        bits[i][j]=b;
                    }
            }
        for(int i=0;i<32;i++)
            {
                int l=0;
                for(int j=0;j<n;j++)
                    {
                        if(bits[j][i]==1)
                            l++;
                    }
                maxl=max(maxl,l);
            }
        return maxl;
    }
};