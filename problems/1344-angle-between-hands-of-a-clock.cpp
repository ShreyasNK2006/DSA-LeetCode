/*
 * Problem 1344: Angle Between Hands of a Clock
 * URL     : https://leetcode.com/problems/angle-between-hands-of-a-clock/
 * Solved  : 2026-06-18
 * Runtime : 0 ms
 * Memory  : 8.2 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    double angleClock(int hour, int minutes) {
         double a1= hour*30+1.0*minutes/2;
         double a2=minutes*6;
         double ans = abs(a1-a2);
         return ans>360-ans?360-ans:ans;
         
         
         
         
    }
};