/*
 * Problem 0263: Ugly Number
 * URL     : https://leetcode.com/problems/ugly-number/
 * Solved  : 2025-12-20
 * Runtime : 0 ms
 * Memory  : 7.9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    bool isUgly(int n) {
        if(n<=0)
        return false;
        while(n%2==0)
        {
            n/=2;
        }
        while(n%3==0)
        {
            n/=3;
        }
        while(n%5==0)
        {
            n/=5;
        }
        if(n==1)
        return true;
        else 
        return false;
    }
};