/*
 * Problem 2553: Separate the Digits in an Array
 * URL     : https://leetcode.com/problems/separate-the-digits-in-an-array/
 * Solved  : 2026-05-11
 * Runtime : 4 ms
 * Memory  : 14.4 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        for(int x:nums)
        {
            int n=log10(x);
            int p= (int)pow(10,n);
            while(n>=0)
            {
                int d=x/p;
                res.push_back(d);
                x%=p;
                p/=10;
                n--;
            }
        }
        return res;
    }
};