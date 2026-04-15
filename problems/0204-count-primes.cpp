/*
 * Problem 0204: Count Primes
 * URL     : https://leetcode.com/problems/count-primes/
 * Solved  : 2026-04-02
 * Runtime : 307 ms
 * Memory  : 132.5 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int countPrimes(int n) {
        if(n<=1)
        return 0;
        int c=0;
        vector<int> prime(n-2,1);
        for(int i=2;i<=sqrt(n);i+=2)
        {
            for(int x=2;x*i<n;x++)
            {
                prime[x*i-2]=0;
            }
            if(i==2)
            i=1;
        }
        for(int i=0;i<n-2;i++)
        {
            if(prime[i]==1)
            c++;
        }
        return c;
    }
};