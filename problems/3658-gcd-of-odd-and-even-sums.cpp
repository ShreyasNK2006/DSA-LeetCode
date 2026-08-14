/*
 * Problem 3658: GCD of Odd and Even Sums
 * URL     : https://leetcode.com/problems/gcd-of-odd-and-even-sums/
 * Solved  : 2026-07-15
 * Runtime : 0 ms
 * Memory  : 8.5 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int gcd(int a,int b)
    {
        if(b==0)
        return a;
        return gcd(b,a%b);
    }
    int gcdOfOddEvenSums(int n) {
        int os=0,es=0;
        for(int i=1;i<=2*n;i++)
        {
            if(i%2==0)
            es+=i;
            else
            os+=i;
        }
        return gcd(os,es);
    }
};