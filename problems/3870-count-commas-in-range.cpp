/*
 * Problem 3870: Count Commas in Range
 * URL     : https://leetcode.com/problems/count-commas-in-range/
 * Solved  : 2026-09-08
 * Runtime : 0 ms
 * Memory  : 8.6 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int countCommas(int n) {
        int count=0;
                if(n>999&& n<10000)
                    count+=(n-999);
                else if(n>=10000 && n<100000)
                    count+=(9000 +n-10000+1);
                else if(n==100000)
                    count+=(9000+90000+1);
        return count;
            
    }
};