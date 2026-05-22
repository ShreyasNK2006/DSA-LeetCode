/*
 * Problem 2784: Check if Array is Good
 * URL     : https://leetcode.com/problems/check-if-array-is-good/
 * Solved  : 2026-05-14
 * Runtime : 0 ms
 * Memory  : 26.4 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    bool isGood(vector<int>& nums) {

        int length = nums.size();

        // For a valid "good" array:
        // base[n-1] = [1, 2, 3, ..., n-1, n-1]
        //
        // If nums has size = length,
        // then maximum number should be length - 1.

        int expectedSum = 0;
        int expectedSquareSum = 0;

        int actualSum = 0;
        int actualSquareSum = 0;

        int maxElement = length - 1;

        // Expected sum:
        // 1 + 2 + ... + (n-1) + (n-1)
        expectedSum =
            (maxElement * (maxElement + 1)) / 2 + maxElement;

        // Expected square sum:
        // 1^2 + 2^2 + ... + (n-1)^2 + (n-1)^2
        expectedSquareSum =
            (maxElement * (maxElement + 1) * (2 * maxElement + 1)) / 6
            + (maxElement * maxElement);

        // Calculate actual sum and actual square sum
        for (int num : nums) {
            actualSum += num;
            actualSquareSum += num * num;
        }

        // Array is good only if both values match
        return (expectedSum == actualSum &&
                expectedSquareSum == actualSquareSum);
    }
};