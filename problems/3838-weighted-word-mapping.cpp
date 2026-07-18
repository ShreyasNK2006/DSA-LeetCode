/*
 * Problem 3838: Weighted Word Mapping
 * URL     : https://leetcode.com/problems/weighted-word-mapping/
 * Solved  : 2026-06-13
 * Runtime : 0 ms
 * Memory  : 43.5 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res;
        int sum=0;
        for(int i=0;i<words.size();i++)
        {
            sum=0;
            for(auto c:words[i])
            sum+=weights[c-'a'];
            sum%=26;
            res+=('z'-sum);
        }
        return res;
    }
};