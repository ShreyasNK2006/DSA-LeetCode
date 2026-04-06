/*
 * Problem 1323: Maximum 69 Number
 * URL     : https://leetcode.com/problems/maximum-69-number/
 * Solved  : 2026-04-02
 * Runtime : 0 ms
 * Memory  : 8 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int maximum69Number (int num) {
        int res=0;
        while(num)
        {
            res*=10;
            int temp = num%10;
            res+=temp;
            num/=10;
        }
        int res2=0;
        int cond=1;
        while(res)
        {
            res2*=10;
            if(res%10==6 && cond==1)
            {
                res2+=9;
                cond=0;
            }
            else
            res2+=(res%10);
            res/=10;
        }
        return res2;
    }
};