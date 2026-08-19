/*
 * Problem 3954: Sum of Compatible Numbers in Range I
 * URL     : https://leetcode.com/problems/sum-of-compatible-numbers-in-range-i/
 * Solved  : 2026-06-07
 * Runtime : 0 ms
 * Memory  : 8.5 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int sum=0;
        for(int i=max(0,n-k);i<n;i++)
            {
                if((n&i)==0)
                    sum+=i;
            }
        for(int i=n+1;i<=n+k;i++)
            {
                if((i&n)==0)
                    sum+=i;
            }
        return sum;
    }
    
};