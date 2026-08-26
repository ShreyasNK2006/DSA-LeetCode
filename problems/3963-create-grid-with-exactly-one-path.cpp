/*
 * Problem 3963: Create Grid With Exactly One Path
 * URL     : https://leetcode.com/problems/create-grid-with-exactly-one-path/
 * Solved  : 2026-06-23
 * Runtime : 0 ms
 * Memory  : 10.9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string temp;
        for(int i=0;i<n;i++)
        temp.push_back('#');
        vector<string> res(m,temp);
        for(int i=0;i<m;i++)
        {
            res[i][0]='.';
        }
        for(int i=0;i<n;i++)
        {
            res[m-1][i]='.';
        }
        return res;
    }
};