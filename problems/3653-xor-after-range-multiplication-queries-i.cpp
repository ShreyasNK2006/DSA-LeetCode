/*
 * Problem 3653: XOR After Range Multiplication Queries I
 * URL     : https://leetcode.com/problems/xor-after-range-multiplication-queries-i/
 * Solved  : 2026-04-08
 * Runtime : 62 ms
 * Memory  : 157.9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

# define MOD 1000000007
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=queries.size();
        int m=nums.size();
       for(int i=0;i<n;i++)
           {
               int st=queries[i][0],end=queries[i][1],jump=queries[i][2];
               long long factor=queries[i][3];
               while(st<=end)
                   {
                    nums[st]=(factor*nums[st])%MOD;
                       st+=jump;
                   }
           }
        int res=0;
        for(int i=0;i<m;i++)
            res=res^nums[i];
        return res;
    }
};