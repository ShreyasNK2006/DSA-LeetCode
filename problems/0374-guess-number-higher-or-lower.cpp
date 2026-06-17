/*
 * Problem 0374: Guess Number Higher or Lower
 * URL     : https://leetcode.com/problems/guess-number-higher-or-lower/
 * Solved  : 2026-05-17
 * Runtime : 2 ms
 * Memory  : 7.9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long l=1,h=n;
        long long mid=(l+h)/2;
        int x=guess(mid);
        while(x!=0)
        {
            if(x==-1)
            h=mid-1;
            else
            l=mid+1;
            mid=(l+h)/2;
            x=guess(mid);
        }
        return mid;
    }
};