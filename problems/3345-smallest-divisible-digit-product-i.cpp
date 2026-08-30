/*
 * Problem 3345: Smallest Divisible Digit Product I
 * URL     : https://leetcode.com/problems/smallest-divisible-digit-product-i/
 * Solved  : 2026-08-06
 * Runtime : 0 ms
 * Memory  : 8.6 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int smallestNumber(int n, int t) {
        int res = n;
        int f = 1;
        bool cond=false;
        int cp=n;
        int b=cp%10;;
        while(cp)
        {
            f*=(cp%10);
            cp/=10;
        }
        while(res%10!=0)
        {
            if(f%t==0)
            break;
            else
            {
                f/=b;
                f*=(b+1);
                b++;
            }
            res++;
        }
        return res;
    }
};