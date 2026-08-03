/*
 * Problem 3754: Concatenate Non-Zero Digits and Multiply by Sum I
 * URL     : https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/
 * Solved  : 2026-07-07
 * Runtime : 3 ms
 * Memory  : 8.9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0,x=0,count=0,copy=n,temp=1;
        while(copy)
            {
                sum+=copy%10;
                if(copy%10)
                {
                    if(count)
                        temp*=10;
                    x+=((copy%10)*(temp));
                    count++;
                }
                copy/=10;
            }
        return sum*x;
        
    }
};