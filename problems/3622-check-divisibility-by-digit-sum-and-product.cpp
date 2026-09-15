/*
 * Problem 3622: Check Divisibility by Digit Sum and Product
 * URL     : https://leetcode.com/problems/check-divisibility-by-digit-sum-and-product/
 * Solved  : 2026-08-22
 * Runtime : 0 ms
 * Memory  : 7.8 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    bool checkDivisibility(int n) {
       int digisum =0,digiprod = 1,sum =0;
        int copy = n;
        while(copy>0)
            {
                digisum += copy%10;
                digiprod *=copy%10;
                copy/=10;
            }
        sum = digisum + digiprod;
        if(n%sum == 0)
            return true;
        else
            return false;
    }
};