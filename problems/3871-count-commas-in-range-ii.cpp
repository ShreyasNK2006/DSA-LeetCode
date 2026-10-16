/*
 * Problem 3871: Count Commas in Range II
 * URL     : https://leetcode.com/problems/count-commas-in-range-ii/
 * Solved  : 2026-09-09
 * Runtime : 0 ms
 * Memory  : 9.1 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    long long countCommas(long long n) {
        long long count=0;
        long long res=0;
        int counter=3;
                while((pow(10,counter))<=n)
                    {
                        if(n<(pow(10,counter+1)))
                            res=res+((n-pow(10,counter)+1)*(counter/3));
                        else
                        {
                           res+=((pow(10,counter+1)-(pow(10,counter)))*(counter/3));
                        }
                        counter++;                      
                    }
        return res;
            
    }
};